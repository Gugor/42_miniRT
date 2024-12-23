/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/23 17:40:30 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

# include "vectors.h"

typedef struct s_scene t_scene;

typedef struct	s_camera
{
	float	fovH;
	float	fovV;
	t_vec3	axis;
	t_p3	pos;
	t_p3	center;
	float	focal_length;
	float	h;
	t_vec3	lookfrom;
	t_vec3	lookat;
	t_vec3	vup;
	float	pixel_sample_scale;
	float	near_plane;
	float	far_plane;
	float	foc_dist;
	int		samples_per_pixel;
	int		max_depth;
	t_vec3	u;
	t_vec3	v;
	t_vec3	w;
}	t_camera;

void	init_camera(t_scene *scn);
#endif
