/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/22 21:02:37 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"
#include "maths.h"
#include <math.h>


static float	calculate_focal_length(t_scene *scn)
{
	float	theta;

	theta = degrees_to_radians(scn->camera.fovV);
	// return (scn->win->img_width / (2.0 * tan(fov_radianes / 2.0)));
	// return ((2 * scn->camera.near_plane) / scn->win->img_height);
	printf("FOV rads: %f\n", theta);
	return (tan(theta / 2.0));
}

void	init_camera(t_scene *scn)
{
	t_camera	*cam;

	cam = &scn->camera;
	cam->center = vec3(0.0, 0.0, 0.0);
	// cam->focal_length = 1;
	printf("Focal lenght: %f\n", cam->focal_length);
	cam->samples_per_pixel = 10;
	cam->near_plane = 0.1;
	cam->far_plane = 1000.1;
	cam->max_depth = 100;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
	cam->lookfrom = vec3(0,0,0);
	cam->vup = vec3(0, 1, 0);
	cam->h = calculate_focal_length(scn);
	cam->focal_length = 1;
	cam->w = normalize_v3(sub_v3(cam->lookfrom, cam->lookat));
	cam->u = normalize_v3(cross(&cam->vup, &cam->w));
	cam->v = cross(&cam->w, &cam->u);
}
