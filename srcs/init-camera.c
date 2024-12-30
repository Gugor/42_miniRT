/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/30 14:16:28 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"
#include "maths.h"
#include <math.h>


static float	calculate_fovV(t_camera *cam)
{
	float	theta;

	theta = degrees_to_radians(cam->fovV);
	return (tan(theta / 2.0));
}
/**
 * @brief It initialize the camera. Some values are hardcoded here.
 * https://www.notion.so/Perspective-Proyection-163d5efd079e80b5afd7d7005886b577
 * `u`, unit vector pointing to the camera right
 * `v`, unit vector pointing to the camera down
 *  `fordwards`, unit vector pointing to fordwards direction. In our case `-z`.
 */
void	init_camera(float aspect_ratio, t_camera *cam)
{
	// (void)aspect_ratio;
	t_interval inter;
	cam->center = cam->lookfrom;
	cam->foc_dist = 10;
	cam->samples_per_pixel = 10;
	cam->near_plane = 0.0001;
	cam->far_plane = 1000.0001;
	cam->max_depth = 50;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
	init_limits(&inter, 0.0, 90.0);
	cam->fovV = cam->fovH / aspect_ratio;
	//cam->fovV = clamp(&inter, cam->fovH * aspect_ratio);
	cam->h = calculate_fovV(cam);
	cam->vup = vec3(0, 1, 0);
	// cam->focal_length = length_v3(sub_v3(cam->lookfrom, cam->lookat));
	// printf("Focal lenght: %f\n", cam->focal_length);
	cam->fordwards = normalize_v3(sub_v3(cam->lookfrom, cam->lookat));
	cam->u = normalize_v3(cross(&cam->vup, &cam->fordwards));
	cam->v = cross(&cam->fordwards, &cam->u);
	printf("=> Initialize Camera\n");
	printf("	:: Center[%f,%f,%f]\n", cam->center.x, cam->center.y, cam->center.z);
	printf("	:: W[%f,%f,%f]\n", cam->fordwards.x, cam->fordwards.y, cam->fordwards.z);
	printf("	:: U[%f,%f,%f]\n", cam->u.x, cam->u.y, cam->u.z);
	printf("	:: V[%f,%f,%f]\n", cam->v.x, cam->v.y, cam->v.z);
	printf("	:: h[%f] - vFoV[%f]\n", cam->h, cam->fovV);
}
