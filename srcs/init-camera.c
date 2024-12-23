/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/23 18:52:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"
#include "maths.h"
#include <math.h>


static float	calculate_fovH(t_camera *cam)
{
	float	theta;

	theta = degrees_to_radians(cam->fovH);
	return (tan(theta / 2.0));
}

void	init_camera(t_scene *scn)
{
	t_camera	*cam;

	cam = &scn->camera;
	cam->foc_dist = 10;
	cam->lookfrom = vec3(cam->pos.x, cam->pos.y, cam->pos.z);
	cam->samples_per_pixel = 1;
	cam->near_plane = 0.1;
	cam->far_plane = 1000.1;
	cam->max_depth = 1;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
	cam->center = cam->lookfrom;
	cam->h = calculate_fovH(cam);
	cam->focal_length = 1;
	printf("Focal lenght: %f\n", cam->focal_length);
	cam->w = normalize_v3(sub_v3(cam->lookfrom, cam->lookat));
	cam->u = normalize_v3(cross(&cam->vup, &cam->w));
	cam->v = cross(&cam->w, &cam->u);
	cam->vup = vec3(0, 1, 0);
}
