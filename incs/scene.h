/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/10 12:59:08 by hmontoya         ###   ########.fr       */
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
# include "ray.h"
# include "entity-data.h"
# include "window.h"

# define NUM_ENTITIES 8
# define NUM_SHAPES 4

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

//hit(const ray& r, double ray_tmin, double ray_tmax, hit_record& rec)
typedef struct s_scene	t_scene;
typedef struct s_lst	t_lst;
typedef void			(*t_create_entity)(t_scene *, const char *line);
typedef int				(*t_is_hit)(void *, const t_ray *, t_interval *, t_hit_data *);

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
	t_is_hit			check_hit[NUM_SHAPES];
	t_lst				*lights;
	t_lst				*shapes;
}	t_scene;

t_scene		*scene_storage(t_scene *storage);
int			init_scene_data(t_scene *scene);
t_scene		*get_scene(void);

#endif
