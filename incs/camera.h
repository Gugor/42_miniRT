/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/12 14:01:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

# include "vectors.h"

typedef struct s_scene t_scene;

typedef struct	s_camera
{
	double	fovH;
	double	fovV;
	t_vec3	axis;
	t_p3	pos;
	t_p3	center;
	double	focal_length;
	double	pixel_sample_scale;
	int		samples_per_pixel;
}	t_camera;

void	init_camera(t_scene *scn);
#endif
