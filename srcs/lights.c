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
    // hl->half_dir = normalize_v3(div_v3_dbl(sum_v3(hl->dir_norm, hl->view_dir), (double)2.0));
    hl->half_dir = normalize_v3(sum_v3(hl->dir_norm, hl->view_dir));
	hl->diffuse = dot(&hitd->normal, &hl->half_dir);
	// if (hl->diffuse >= 0)
		// return (hl->rgb);
    hl->specular = pow(fmax(hl->diffuse, 0.0f), 3200);
	// if (hl->specular < 0)
	// 	hl->specular = -hl->specular;
	// if (is_brighter(hl->rgb, sum_rgb(hl->rgb, scale_color(hl->rgb, hl->specular))))
	// 	return (hl->rgb);
	// if (hl->diffuse <= 1e-4)
	return (sum_rgb(hl->rgb, scale_color(light->rgb, hl->specular)));
}

static t_color	calculate_highlights(t_hit_data *hitd, t_light *light, t_highlight *hl)
{
	// t_vec3		dir_to_hit;
	// t_vec3		quad;

	// quad.x = 1;
	// quad.y = 0.1;
	// quad.z = 0.01;
	hl->diffuse = dot(&hl->dir_norm, &hitd->normal);
	// hl->dist_to_light = length_v3(hl->dir);
	// hl->attenuation = 1 / (quad.x + (quad.y * hl->dist_to_light)
	// 		+ (quad.z * hl->dist_to_light * hl->dist_to_light));
	// hl->intensity = 100 * hl->attenuation * hl->diffuse;
	hl->intensity = hl->diffuse;
	// printf("Higlights intensity %f\n", hl->intensity);
	// if (hl->intensity < -0.001)
	// 	return (hl->rgb);
	return (scale_color(sum_rgb(hl->rgb, light->rgb), hl->intensity));
}

static bool shadow_hit(const t_ray *ray, t_hit_data *rec)
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

static t_color	calculate_shadows(t_hit_data *hitd, t_highlight *hl)
{
	double	diffuse;
	diffuse = dot(&hl->dir_norm, &hitd->normal);
	printf("Diffuse: %f\n", diffuse);
	// if (diffuse > 1e-6)
	// 	diffuse = 0;
	return (sum_rgb(hl->rgb, scale_color(hl->rgb, (1 - fabs(diffuse)))));
}
void	calculate_lights(t_hit_data *hitd)
{
	t_lst			*lights;
	t_light			*light;
	// t_color			total_light;
	t_hit_data 		hitl;
	t_highlight		hl;
	bool hit_anything;
	t_ray	ray;

	lights = get_scene()->lights;
	hl.rgb = ambient_light_calc(hitd->rgb, &get_scene()->alight);
	// hl.rgb = hitd->rgb;
	while (lights)
	{
		light = (t_light *)lights->cnt;
		hl.origin = light->pos;
		// printf("Light pos: [%f,%f,%f]\n", light->pos.x, light->pos.y, light->pos.z);
		hl.dir = sub_v3(hl.origin, hitd->hit);
		hl.dir_norm = normalize_v3(hl.dir);
		ray = init_ray(&hitd->hit, &hl.dir);
		hit_anything = false;
		init_limits(&ray.lim, 0.01, length_v3(hl.dir));
		hit_anything = shadow_hit(&ray, &hitl);
			hl.rgb = sum_rgb(hl.rgb, calculate_highlights(hitd, light, &hl));
			hl.rgb = sum_rgb(hl.rgb, calculate_phong(hitd, light, &hl));
		if (hit_anything)
		{
			// hl.rgb = sum_rgb(hl.rgb, color(0,0,0));
			hl.rgb = sum_rgb(hl.rgb, calculate_shadows(hitd, &hl));
		}
		// else
		lights = lights->next;
	}
	hitd->rgb = hl.rgb;
}
