/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:07 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/13 00:05:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "ray.h"
#include "maths.h"
#include "vectors.h"
#include "colours.h"
#include "shapes.h"
#include "shape-maths.h"
#include "rendering.h"
#include "lights.h"

/**
 * @brief It sends a ray from the screen to the world and check the
 * intersections with wolrd objects.
 * @returns
 * the color of the closest intersection point.
*/
t_color	ray_color(const t_ray *ray, long max_depth)
{
	t_hit_data	hitd;
	t_vec3		dir;
	t_ray		new;

	hitd.rgb = color(0, 0, 0);
	if (max_depth <= 0)
		return (color(0, 0, 0));
	init_limits((t_interval *)&ray->lim, 0.001, INFINITY);
	if (hit(ray, (t_interval *)&ray->lim, &hitd))
	{
		dir = random_on_hemisphere(hitd.normal);
		new = init_ray(&hitd.hit, &dir, ray->lim.min, ray->lim.max);
		calculate_lights(&hitd);
		return (mean_rgb(hitd.rgb, ray_color(&new, --max_depth)));
	}
	hitd.normal = normalize_v3(ray->direction);
	hitd.rgb.clr = lerprgb(hitd.normal.y, color(255, 255, 255),
			color(127, 178, 255));
	hitd.rgb = ambient_light_calc(hitd.rgb, &get_scene()->alight);
	return (hitd.rgb);
}

/**
 * @brief It updates the direction of a ray
 */
t_ray	get_ray(t_window *win, t_camera *camera, t_ivec2 *pix_pos)
{
	t_vec3	pixel_sample;
	t_ray	ray;
	t_vec3	ray_dir;

	pixel_sample = get_pix_rand_pos(&win->p00, &win->pixel_delta_u,
			&win->pixel_delta_v, pix_pos);
	ray_dir = sub_v3(pixel_sample, camera->center);
	ray = init_ray((t_vec3 *)&camera->center, &ray_dir, 0.0001, INFINITY);
	return (ray);
}

/**
 * @brief It finds a a point in a ray. T is a scalar that set the distance
 * to scale form origin.
 */
t_vec3	at(t_ray *r, double t)
{
	t_vec3	dt;

	dt = scale_v3(r->direction, t);
	return (sum_v3(r->origin, dt));
}

/**
 * @brief It creates a ray from an origin with a direction.
 */
t_ray	init_ray(t_vec3 *origin, t_vec3 *dir, double min, double max)
{
	t_ray	ray;

	ray.origin = *origin;
	ray.direction = *dir;
	ray.ray = sub_v3(*dir, *origin);
	ray.length = length_v3(ray.ray);
	ray.norm = normalize_v3(ray.ray);
	init_limits(&ray.lim, min, max);
	return (ray);
}
