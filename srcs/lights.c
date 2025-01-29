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

static t_color	calculate_highlights(t_hit_data *hitd, t_light *light)
{
	t_higlight	hl;
	t_vec3		quad;
	t_vec3		dir_to_hit;

	quad.x = 1;
	quad.y = 0.1;
	quad.z = 0.01;
	hl.dir = normalize_v3(sub_v3(light->pos, hitd->hit));
	dir_to_hit = scale_v3(hl.dir, -1);
	hl.diffuse = dot(&hitd->out_normal, &hl.dir);
	hl.dist_to_light = length_v3(sub_v3(light->pos, hitd->hit));
	if (hl.diffuse < 1e-4)
		hl.diffuse = 0;
	hl.attenuation = 1 / (quad.x + (quad.y * hl.dist_to_light)
			+ (quad.z * hl.dist_to_light * hl.dist_to_light));
	hl.view_dir = normalize_v3(sub_v3(get_scene()->camera.pos, hitd->hit));
    hl.half_dir = normalize_v3(sum_v3(hl.dir, hl.view_dir));
    hl.specular = pow(fmax(dot(&hitd->out_normal, &hl.half_dir), 0.0), 1024);
	// hl.intensity = hl.specular * light->brghtnss * hl.diffuse;
	hl.intensity = hl.specular * hl.attenuation * light->brghtnss * hl.diffuse * 10000;
	printf("Higlights intensity %f\n", hl.intensity);
	if (hl.intensity < -0.001)
		return (hitd->rgb);
	return (sum_rgb(hitd->rgb, scale_color(light->rgb, hl.intensity)));
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

// static t_color	calculate_shadows(t_ray *ray, t_hit_data *hitd, t_light *light)
// {
// 	double	diffuse;

// 	diffuse = dot(&hitd->out_normal, &ray->norm);
// 	return (scale_color((hitd->rgb), (1 - light->brghtnss) * (1 - diffuse)));
// }
void	calculate_lights(t_hit_data *hitd)
{
	t_lst		*lights;
	t_light		*light;
	t_color		highlight;
	t_hit_data 	hitl;
	bool hit_anything;
	t_ray	ray;

	lights = get_scene()->lights;
	hitd->rgb = ambient_light_calc(hitd->rgb, &get_scene()->alight);
	while (lights)
	{
		light = (t_light *)lights->cnt;
		ray = init_ray(&hitd->hit, &light->pos);
		hit_anything = false;
		init_limits(&ray.lim, 0.001, ray.length);
		hit_anything = shadow_hit(&ray, &hitl);
		if (hit_anything && dot(&hitd->hit, &light->pos) > 0)
		{
			highlight = calculate_shadows(&ray, hitd, light);
		}
		// else
		// 	highlight = calculate_highlights(hitd, light);
		hitd->rgb = sum_rgb(hitd->rgb, highlight);
		lights = lights->next;
	}
}
