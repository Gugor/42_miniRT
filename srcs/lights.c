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

static t_color	calculate_shadows(t_ray *ray, t_hit_data *hitd, t_light *light)
{
	double	dist;
	double	intensity;
	t_vec3	quad;
	t_color	new_color;
	double	diffuse_factor;
	// t_vec3	dir;

	quad.x = 1;
	quad.y = 0.1;
	quad.z = 0.01;

	dist = ray->length;
	// dist = 1;
	// dir = normalize_v3(sub_v3(light->pos, hitd->hit));
	diffuse_factor = dot(&hitd->out_normal, &ray->norm);
	if (diffuse_factor < 1e-6)
		diffuse_factor = 0;
	
	intensity = 1 / (quad.x + (quad.y * dist) + (quad.z * dist * dist));
	intensity = intensity * light->brghtnss * diffuse_factor;
	if (hitd->type == 3 && diffuse_factor > 0)
		printf("Sphere Diffuse %f\n", diffuse_factor);
	new_color = sum_rgb(
		// sum_rgb(hitd->rgb, scale_color(hitd->rgb, 1 - intensity)), // Atenuación de la luz ambiental
			hitd->rgb,
			scale_color(light->rgb, intensity)
			);
	return (new_color);
}

void	calculate_lights(t_hit_data *hitd)
{
	t_lst	*lights;
	t_light	*light;
	t_scene *scn;
	t_ray	ray;
	t_color new_color = {0};
	// t_interval	lim;
	t_hit_data	hitl;

	// hitl.rgb = color(1,0,0);
	scn = get_scene();
	lights = scn->lights;
	while (lights)
	{
		// t_vec3 r = sum_v3(hitd->hit, scale_v3(hitd->out_normal, 0.01));
		light = (t_light *)lights->cnt;
		ray = init_ray(&hitd->hit, &light->pos);
		// ray = init_ray(&light->pos, &hitd->hit);
		init_limits(&ray.lim, 0.01, length_v3(sub_v3(light->pos, hitd->hit)));
		// init_limits(&ray.lim, 0.001, INFINITY);
		new_color = calculate_shadows(&ray, hitd, light);
		ray = init_ray(&light->pos, &hitd->hit);
		if (shadow_hit(&ray, &ray.lim, &hitl))
		{
			if (hitd->type == 3)
				printf("Dark side\n");
			new_color = sum_rgb(new_color, color(0, 0, 0));
			// new_color = color(0, 0, 0);
			lights = lights->next;
			continue;
		}
		// new_color = sum_rgb(new_color, calculate_shadows(&ray, hitd, light));
		lights = lights->next;
	}
	hitd->rgb = new_color;
}