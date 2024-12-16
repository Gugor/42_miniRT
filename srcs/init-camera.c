/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:46:06 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"

void init_camera (t_scene *scn)
{
	t_camera *cam;

	cam = &scn->camera;
	cam->center = vec3(0.0,0.0,0.0);
	cam->focal_length = 1;
	cam->samples_per_pixel = 10;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
}
