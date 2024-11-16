/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 18:47:25 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related to the program itself  and the scene
*/
#ifndef MINIRT_H
#define MINIRT_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lights.h"
#include "camera.h"
#include "shapes.h"

typedef struct s_scene
{
	unsigned int	height;
	unsigned int	width;
	int		rtfd;
	char		*entity_ids[8];
	t_camera	camera;
	t_ambient	ambient_light;
	t_light		*lights;
	t_plane		*planes;
	t_sphere	*spheres;
	t_cylinder	*cylinders;
}	t_scene;


t_scene 	*scene_storage(t_scene *storage);
t_scene 	*get_scene(void);

#endif
