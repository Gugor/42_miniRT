/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 20:03:59 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related to the program itself  and the scene
*/
#ifndef SCENE_H
# define SCENE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>

# include "lights.h"
# include "camera.h"
# include "shapes.h"

# define NUM_ENTITIES 7


typedef enum e_ent_id
{
	AMBIENT,
	LIGHT,
	CAMERA,
	PLANE,
	SPHERE,
	CYLINDER,
	OTHER,
}	t_entid;

/**
* @brief Its used for stablishing if a scene can be rendered
* A series of values to mask an compare with, to stablish if all the
* required entity are set to a scene being able to render.
*/
typedef enum e_req_ents
{
	REQ_AMBIENT = 1,
	REQ_CAMERA = 2,
	REQ_FULL = 3,
}	t_reqents;


typedef struct s_scene	t_scene;

typedef int	(*t_create_entity)(t_scene *, char *line);

typedef struct s_scene
{
	unsigned int		height;
	unsigned int		width;
	int					rtfd;
	uint8_t				required_ents;	
	char				*entity_ids[NUM_ENTITIES + 1];
	t_create_entity		create_ent[7];
	t_camera			camera;
	t_ambient			alight;
	t_shape_lst			*shapes;
	//t_light_lst			*lights;
	//t_plane				*planes;
	//t_sphere			*spheres;
	//t_cylinder			*cylinders;
}	t_scene;

t_scene		*scene_storage(t_scene *storage);
int			init_scene_data(t_scene *scene);
t_scene		*get_scene(void);

#endif
