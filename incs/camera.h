/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:00 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/07 20:06:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

# include "vectors.h"
# include "camera.h"

typedef struct s_scene t_scene;

typedef struct	s_camera
{
	double	fovH;
	double	fovV;
	t_vec3	axis;
	t_p3	pos;
	t_p3	center;
	double	focal_length;
	double	h;
	t_vec3	lookfrom;
	t_vec3	lookat;
	t_vec3	vup;
	double	pixel_sample_scale;
	double	near_plane;
	double	far_plane;
	double	foc_dist;
	int		samples_per_pixel;
	long		max_depth;
	t_vec3	u;
	t_vec3	v;
	t_vec3	fordwards;
}	t_camera;

void	init_camera(t_camera *cam);
#endif
