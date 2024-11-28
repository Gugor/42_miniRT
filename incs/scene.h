/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 19:47:18 by hmontoya         ###   ########.fr       */
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
# include "lists.h"
# include "entity-data.h"
# include "window.h"

# define NUM_ENTITIES 8

/**
* @brief Its used for stablishing if a scene can be rendered
* A series of values to mask an compare with, to stablish if all the
* required entity are set to a scene being able to render.
*/
typedef enum e_req_ents
{
	REQ_AMBIENT = 1,
	REQ_CAMERA = 2,
	REQ_LIGHT = 3,
	REQ_FULL = 4,
}	t_reqents;


typedef struct s_scene	t_scene;
typedef struct s_lst	t_lst;
typedef void			(*t_create_entity)(t_scene *, const char *line);

typedef struct s_scene
{
	uint8_t				required_ents;	
	t_window			*win;
	int					rtfd;
	int					num_lights;
	int					num_shapes;
	char				*entity_ids[NUM_ENTITIES + 1];
	t_color				*img_pixels;
	t_ambient			alight;
	t_camera			camera;
	t_create_entity		create_ent[NUM_ENTITIES];
	t_lst				*lights;
	t_lst				*shapes;
}	t_scene;

t_scene		*scene_storage(t_scene *storage);
int			init_scene_data(t_scene *scene);
t_scene		*get_scene(void);

#endif
