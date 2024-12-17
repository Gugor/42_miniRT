/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray-cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:44:07 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/17 11:39:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "ray.h"
#include "maths.h"
#include "vectors.h"
#include "colours.h"
#include "shapes.h"
#include "shape-maths.h"
#include "rendering.h"

t_color tst_ray_color(const t_ray *r)
{
    t_vec3 norm;
	t_p3	sp;
	t_color res;
	float	t;
	
	sp.x = 0;
	sp.y = 0;
	sp.z = 0;

	t = tst_hit_sphere((void *)&sp, 0.5, r) >= 0;
	if (t > 0.0)
	{
		t_vec3 sdet = at((t_ray *)r, t);
		t_vec3 rest = rest_v3(sdet, sp);
		t_vec3 N = normalize_v3(rest);
		t_color c;
		c = scale_rgb((N.x + 1) * 0.5, (N.y + 1) * 0.5, (N.z + 1) * 0.5);
        return (c);
	}
	// printf("Drawing Backround\n");
	norm = (*r).norm;
	//printf("=> Ray[%f] Norm[%f,%f,%f]\n", r->length, norm.x, norm.y, norm.z);
	res.clr = lerpRGB(norm.y, scale_rgb(1.0, 1.0,1.0), scale_rgb(0.5, 0.7, 1.0));
	// printf("	::A [%f]RGB[%u,%u,%u][%i]\n", norm.y, (res.clr >> 16) & 0xFF, (res.clr >> 8) & 0xFF , res.clr & 0xFF, res.clr);
	return (res);

}
typedef struct s_interval t_interval;

t_color ray_color(const t_ray *ray)
{
	t_hit_data	hitd;
	t_vec3		dir;
	t_ray		new;

	init_limits((t_interval *)&ray->lim, 0, INFINITY);
	if (hit(ray, (t_interval *)&ray->lim, &hitd))
	{
		// printf("Hiting object\n");
		// hitd.rgb = scale_rgb((hitd.normal.x + 1) * 0.5, (hitd.normal.y + 1) * 0.5, (hitd.normal.z + 1) * 0.5);
		// hitd.rgb = clamp_color((uint32_t)hitd.rgb.clr);
		// return (hitd.rgb);
		// dir = hitd.normal;
		dir = random_on_hemisphere(hitd.normal);
		new = init_ray(&hitd.hit, &dir);
		hitd.rgb = mult_rgb_dbl(ray_color(&new), 0.5);
		// hitd.rgb = color(1,0,0);
		return (hitd.rgb);
	}
	hitd.normal = normalize_v3(ray->direction);
	// printf("=> Ray[%f] Norm[%f,%f,%f]\n", ray->length, hitd.normal.x, hitd.normal.y, hitd.normal.z);
	hitd.rgb.clr = lerpRGB(hitd.normal.y, scale_rgb(1.0, 1.0, 1.0), scale_rgb(0.5, 0.7, 1.0));
	// printf("	::A [%f]RGB[%u,%u,%u][%i]\n", hitd.normal.y, (hitd.rgb.clr >> 16) & 0xFF, (hitd.rgb.clr >> 8) & 0xFF , hitd.rgb.clr & 0xFF, hitd.rgb.clr);
	return (hitd.rgb);
}

/**
 * @brief It updates the direction of a ray
 */
t_ray get_ray(t_window *win, t_camera *camera, t_ivec2 *pix_pos)
{
	t_vec3	pixel_sample;
	t_ray	ray;
	t_vec3	ray_dir;

	pixel_sample = get_pix_rand_pos(&win->p00, &win->pixel_delta_u, &win->pixel_delta_v, pix_pos);
	// printf("[%i,%i] - P00[%f,%f,%f]\n", pix_pos->x, pix_pos->y, pixel_sample.x, pixel_sample.y, pixel_sample.z);
	ray_dir = rest_v3(pixel_sample, camera->pos);
	// printf("Cam pos[%f,%f,%f]\n", camera->pos.x, camera->pos.y, camera->pos.z);
	ray = init_ray((t_vec3 *)&camera->pos, &ray_dir);
	return (ray);
}

/**
 * @brief It finds a a point in a ray. T is a scalar that set the distance
 * to scale form origin.
 */
t_vec3			at(t_ray *r, float t)
{
	t_vec3 dt;
	dt = mult_v3_dbl(r->direction, t);
	return (rest_v3(r->origin, dt));
}

/**
 * @brief It creates a ray from an origin with a direction.
 */
t_ray  init_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray ray;
	// printf("=> Init ray:\n");
	ray.origin = *origin;
	// printf("	::or[%f,%f,%f]\n ", ray.origin.x, ray.origin.y, ray.origin.z);
	ray.direction = *dir;
	// printf("	::dir[%f,%f,%f]\n", ray.direction.x, ray.direction.y, ray.direction.z);
	ray.ray = rest_v3(*dir, *origin);
	ray.length = length_v3(ray.ray);
	ray.norm = normalize_v3(ray.ray);
	return (ray);
}
