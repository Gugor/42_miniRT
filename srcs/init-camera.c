/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/20 18:23:38 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"
#include "maths.h"

static float	calculate_focal_length(t_scene *scn)
{
	float	fov_radianes;

	fov_radianes = degrees_to_radians(scn->camera.fovV);
	return (scn->win->img_width / (2.0 * tan(fov_radianes / 2.0)));
}

void	init_camera(t_scene *scn)
{
	t_camera	*cam;

	cam = &scn->camera;
	cam->center = vec3(0.0, 0.0, 0.0);
	cam->focal_length = calculate_focal_lenght(scn);
	cam->samples_per_pixel = 10;
	cam->max_depth = 50;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
}
