/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:50 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "vectors.h"

typedef struct	s_camera
{
	double	fovH;
	double	fovV;
	t_vec3	axis;
	t_p3	pos;
	t_p3	center;
}	t_camera;

#endif
