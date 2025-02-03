/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/03 19:04:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"
#include "maths.h"
#include <math.h>


static double	calculate_fovv(t_camera *cam)
{
	double	theta;

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
void	init_camera(t_camera *cam)
{
	t_interval inter;

	cam->center = cam->lookfrom;
	cam->samples_per_pixel = 1;
	cam->near_plane = 0.001;
	cam->far_plane = 100;
	cam->max_depth = 1;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
	init_limits(&inter, 0.0, 90.0);
	cam->fovV = cam->fovH * (16/9);
	printf("FoVH=%f * (%f) = FoVV:%f\n", cam->fovH, (double)(90.0f / 180.0f), cam->fovV);
	cam->foc_dist = 1;
	cam->h = calculate_fovv(cam);
	cam->vup = vec3(0, 1, 0);
	cam->fordwards = scale_v3(cam->lookat, -1);
	cam->u = normalize_v3(cross(&cam->vup, &cam->fordwards));
	if (!cam->u.x && !cam->u.y &&  !cam->u.z)
		cam->u = vec3(-1,0,0);
	cam->v = cross(&cam->fordwards, &cam->u);
	if (!cam->v.x && !cam->v.y &&  !cam->v.z)
		cam->u = vec3(0,0,1);
	printf("=> Initialize Camera\n");
	printf("	:: Center[%f,%f,%f]\n", cam->center.x, cam->center.y, cam->center.z);
	printf("	:: W[%f,%f,%f]\n", cam->fordwards.x, cam->fordwards.y, cam->fordwards.z);
	printf("	:: U[%f,%f,%f]\n", cam->u.x, cam->u.y, cam->u.z);
	printf("	:: V[%f,%f,%f]\n", cam->v.x, cam->v.y, cam->v.z);
	printf("	:: h[%f] - vFoV[%f]\n", cam->h, cam->fovV);
}
