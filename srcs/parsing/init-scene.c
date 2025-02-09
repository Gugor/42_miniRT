/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 18:20:19 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-handler.h"
#include "scene.h"
#include "parsing.h"
#include "window.h"
#include "shape-maths.h"
#include "events.h"

/**
* @brief It fill entity_id field in scene with the entiy identifiers
* accepted in this program.
* @return `{void}`
*/
static void	set_entity_ids(char *entities[NUM_ENTITIES + 1])
{
	entities[0] = "A";
	entities[1] = "l";
	entities[2] = "C";
	entities[3] = "pl";
	entities[4] = "sp";
	entities[5] = "cy";
	entities[6] = "sq";
	entities[7] = NULL;
}

/**
 * @brief It initialize an array of functions to create the shapes. 
 * @param scene `{t_scene *}` a pointer to the scene data structure.
 * @returns `{void}`
*/
static void	init_entity_delegates(t_scene *scene)
{
	scene->create_ent[AMBIENT] = &create_ambient_light;
	scene->create_ent[LIGHT] = &create_light_src;
	scene->create_ent[CAMERA] = &create_camera;
	scene->create_ent[PLANE] = &create_plane;
	scene->create_ent[SPHERE] = &create_sphere;
	scene->create_ent[CYLINDER] = &create_cylinder;
	scene->create_ent[SQUARE] = &create_square;
	scene->create_ent[EOS] = NULL;
}

/**
 * @brief It initialize the and array of functions used
 * to check the hits on the different available shapes in scene.
 */
static void	init_hit_shape_delegates(t_scene *scene)
{
	scene->check_hit[PLANE - SHAPE_TYPE_OFFSET] = &hit_plane;
	scene->check_hit[SPHERE - SHAPE_TYPE_OFFSET] = &hit_sphere;
	scene->check_hit[CYLINDER - SHAPE_TYPE_OFFSET] = &hit_cylinder;
	scene->check_hit[SQUARE - SHAPE_TYPE_OFFSET] = &hit_square;
	scene->check_hit[4] = NULL;
}

/**
* @brief Initialize the scene and entities with default data.
*/
int	init_scene_data(t_scene *scene, t_window *win)
{
	set_entity_ids(scene->entity_ids);
	init_entity_delegates(scene);
	init_hit_shape_delegates(scene);
	scene->required_ents = 0b00000000;
	scene->lights = NULL;
	scene->num_lights = 0;
	scene->shapes = NULL;
	scene->num_shapes = 0;
	scene->win = win;
	init_events(scene);
	scene_storage(scene);
	return (0);
}

/**
* @brief It gets the scene stored statically by `scene_storage()`.
* @returns `{t_scene *}`
*/
t_scene	*get_scene(void)
{
	return (scene_storage(NULL));
}
