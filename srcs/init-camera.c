/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-camera.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:03 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/18 19:13:33 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "scene.h"
#include "camera.h"

void	init_camera(t_scene *scn)
{
	t_camera	*cam;

	cam = &scn->camera;
	cam->center = vec3(0.0, 0.0, 0.0);
	cam->focal_length = 1;
	cam->samples_per_pixel = 10;
	cam->max_depth = 50;
	cam->pixel_sample_scale = 1.0 / cam->samples_per_pixel;
}
