/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:04:13 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/01/27 18:09:18hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lights.h"
#include "shape-maths.h"
#include "colours.h"

static t_color	calculate_phong(t_hit_data *hitd, t_light *light, t_highlight *hl)
{
	hl->view_dir = normalize_v3(sub_v3(get_scene()->camera.pos, hitd->hit));
    hl->half_dir = normalize_v3(sum_v3(hl->dir_norm, hl->view_dir));
	hl->diffuse = dot(&hitd->normal, &hl->half_dir);
    hl->specular = pow(fmax(hl->diffuse, 0.00001f), 144);
	return (sum_rgb(hl->rgb, scale_color(light->rgb, 20 * hl->specular * light->brghtnss)));
}

static t_color	calculate_highlights(t_hit_data *hitd, t_light *light, t_highlight *hl)
{
	t_vec3		quad;

	quad.x = 1;
	quad.y = 0.1;
	quad.z = 0.01;
	hl->diffuse = fmax(dot(&hl->dir_norm, &hitd->normal), 0.0f);
	hl->dist_to_light = length_v3(hl->dir) / 3 * 100;
	hl->attenuation = 1 / (quad.x + (quad.y * hl->dist_to_light)
			+ (quad.z * hl->dist_to_light * hl->dist_to_light));
	hl->intensity = (hl->attenuation + hl->diffuse) * hl->brightness;
	// hl->intensity = hl->diffuse;
	if (hl->intensity < -0.00001)
		return (hl->rgb);
	return (scale_color(light->rgb, hl->intensity));
}

static bool	shadow_hit(const t_ray *ray, t_hit_data *rec)
{
	t_scene		*scn;
	t_lst		*shapes;
	t_hit_data	hitd;

	scn = get_scene();
	shapes = scn->shapes;
	while (shapes)
	{
		if (scn->check_hit[shapes->type - SHAPE_TYPE_OFFSET]
			((void *)shapes->cnt, ray, (t_interval *)&ray->lim, &hitd))
		{
			if (rec)
				rec = &hitd;
			return (true);
		}
		shapes = shapes->next;
	}
	return (false);
}

static t_color	calculate_shadows(t_hit_data *hitd, t_light *light, t_highlight *hl)
{
	double	diffuse;

	(void)light;
	diffuse = fmax(dot(&hl->dir_norm, &hitd->normal), 0.00001f);
	return (scale_color(scale_color(color(0, 0, 0), (1 + hl->brightness)), diffuse));
}

void	calculate_lights(t_hit_data *hitd)
{
	t_lst			*lights;
	t_light			*light;
	t_hit_data		hitl;
	t_highlight		hl;
	t_ray			ray;

	lights = get_scene()->lights;
	hl.rgb = ambient_light_calc(hitd->rgb, &get_scene()->alight);
	hl.brightness = get_scene()->alight.intensity;
	while (lights)
	{
		light = (t_light *)lights->cnt;
		if (light->brghtnss < get_scene()->alight.intensity)
			hl.brightness = get_scene()->alight.intensity; 
		else
			hl.brightness = light->brghtnss;
		if (light->brghtnss == 0.0f)
		{
			lights = lights->next;
			continue ;
		}
		hl.origin = light->pos;
		hl.dir = sub_v3(hl.origin, hitd->hit);
		hl.dir_norm = normalize_v3(hl.dir);
		ray = init_ray(&hitd->hit, &hl.dir_norm);
		init_limits(&ray.lim, 0.0001f, length_v3(hl.dir));
			
		hl.rgb = sum_rgb(scale_color(hl.rgb, hl.brightness), calculate_highlights(hitd, light, &hl));
		if (shadow_hit(&ray, &hitl))
		{
			if (hitl.id != hitd->id)
				hl.rgb = sum_rgb(hl.rgb, calculate_shadows(hitd, light, &hl));
			lights = lights->next;
			continue ;
		}
		hl.rgb = sum_rgb(hl.rgb, calculate_phong(hitd, light, &hl));
		lights = lights->next;
	}
	hitd->rgb = hl.rgb;
}
