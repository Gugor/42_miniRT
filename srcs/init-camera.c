/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/27 11:18:37 by hmontoya         ###   ########.fr       */
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

void	init_camera(float aspect_ratio, t_camera *cam)
{
	(void)aspect_ratio;
	cam->center = cam->lookfrom;
	cam->foc_dist = 10;
	cam->samples_per_pixel = 10;
	cam->near_plane = 0.1;
	cam->far_plane = 1000.1;
	cam->max_depth = 1;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
	cam->fovV = cam->fovH * 0.5;
	cam->h = calculate_fovV(cam);
	cam->vup = vec3(0, 1, 0);
	// cam->focal_length = length_v3(sub_v3(cam->lookfrom, cam->lookat));
	// printf("Focal lenght: %f\n", cam->focal_length);
	cam->w = normalize_v3(sub_v3(cam->lookfrom, cam->lookat));
	cam->u = normalize_v3(cross(&cam->vup, &cam->w));
	cam->v = cross(&cam->w, &cam->u);
}
