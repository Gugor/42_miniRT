/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:51:30 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/07 16:51:33 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lights.h"
#include "shape-maths.h"
#include "colours.h"
#include "events.h"

/**
 * @brief It calculate the specular reflection of an object. Also called
 * Phong reflections.
 * @returns
 * It returns a color that rerpesents the color intensity for the given point.
*/
static t_color	calculate_phong(t_hit_data *hitd, t_light *light,
	t_highlight *hl)
{
	hl->view_dir = normalize_v3(sub_v3(get_scene()->camera.pos, hitd->hit));
	hl->half_dir = normalize_v3(sum_v3(hl->dir_norm, hl->view_dir));
	hl->diffuse = fmax(dot(&hitd->normal, &hl->half_dir), 0.0f);
	hl->specular = pow(fmax(hl->diffuse, 0.00001f), 100.0f) * light->brghtnss;
	return (scale_color(light->rgb, hl->specular));
}

/**
 * @brief It calculate the light shining on an object.
 * @returns
 * It returns the color intensity of the light for the given point.
*/
static t_color	calculate_highlights(t_hit_data *hitd, t_light *light,
	t_highlight *hl)
{
	t_vec3		quad;

	quad.x = 1;
	quad.y = 0.1;
	quad.z = 0.01;
	(void)hitd;
	if (get_scene()->input_flags & SHADES_MODE)
	{
		hl->dist_to_light = (length_v3(hl->dir));
		hl->attenuation = 1 / (quad.x + (quad.y * hl->dist_to_light)
				+ (quad.z * hl->dist_to_light * hl->dist_to_light));
		hl->intensity = (hl->attenuation + hl->diffuse) * hl->brightness;
	}
	else
		hl->intensity = (hl->diffuse) * hl->brightness;
	return (scale_color(light->rgb, hl->intensity));
}

/**
 * @brief It sends a shadow ray to check if there is any object between
 * a given hit and a source of light.
*/
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

/**
 * @brief It calculates the lighte incidence in a given it on the sceneº
 */
void	calculate_lights(t_hit_data *hitd)
{
	t_lst			*lights;
	t_light			*light;
	t_hit_data		hitl;
	t_highlight		hl;
	t_ray			ray;

	lights = get_scene()->lights;
	init_highlights(&hl, &hitd->rgb);
	while (lights)
	{
		light = (t_light *)lights->cnt;
		update_higlights(&hl, light, hitd);
		ray = init_ray(&hitd->hit, &hl.dir_norm, 0.0001f, length_v3(hl.dir));
		if (!shadow_hit(&ray, &hitl))
		{
			hl.diffuse = fmax(dot(&hl.dir_norm, &hitd->normal), 0.0f);
			hl.diffusse_clr = sum_rgb(hl.diffusse_clr,
					calculate_highlights(hitd, light, &hl));
			hl.specular_clr = sum_rgb(hl.specular_clr,
					calculate_phong(hitd, light, &hl));
		}
		lights = lights->next;
	}
	hitd->rgb = sum_rgb(hl.ambient_clr,
			sum_rgb(hl.specular_clr, hl.diffusse_clr));
}
