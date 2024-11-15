/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:45:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 15:48:40 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAMERA_H
#define CAMERA_H

#include "mrt-math.h"

typedef struct	s_camera
{
	t_p3	pos;
	t_vec3	axis;
	double	fovH;
	double	fovV;
}	t_camera;

#endif
