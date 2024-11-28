/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:56:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 19:30:47 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-handler.h"
#include "scene.h"
#include "parsing.h"
#include "window.h"

/**
* @brief It gets the scene stored statically by `scene_storage()`.
* @returns `{t_scene *}`
*/
t_scene *get_scene(void)
{
	return (scene_storage(NULL));
}

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
	entities[6] = "ot";
	entities[7] = "\0";
}
/**
 * @brief It initialize an array of functions to create the shapes. 
 * @param scene `{t_scene *}` a pointer to the scene data structure.
 * @returns `{void}`
*/
static void	init_entity_delegates (t_scene *scene)
{
	scene->create_ent[AMBIENT] = &create_ambient_light;
	scene->create_ent[LIGHT] = &create_light_src;
	scene->create_ent[CAMERA] = &create_camera;
	scene->create_ent[PLANE] = &create_plane;
	scene->create_ent[SPHERE] = &create_sphere;
	scene->create_ent[CYLINDER] = &create_cylinder;
	scene->create_ent[EOS]	= NULL;
	//scene->create_ent[OTHER] = create_other;
}

/**
* @brief Initialize the scene and entities with default data.
*/
int	init_scene_data(t_scene *scene)
{
	set_entity_ids(scene->entity_ids);
	init_entity_delegates(scene);
	scene->required_ents = 0b00000011;
	scene->lights = NULL;
	scene->num_lights = 0;
	scene->shapes = NULL;
	scene->num_shapes = 0;
	init_window(scene);
	scene_storage(scene);
	return (0);
}

/**
* @brief It stores statically the scene object, te be retrieved when needed.
* @param `{t_scene *}` a pointer to the scene data strcuture.
* @returns `{t_scene *}`
* `a scene`
* `NULL if it no scene has been stored`
* NOTE: this function does not allocates memory it just stores a pointer to
* memory.
* so be aware where this memory is allocate and take messures in case you need
* to manually free it.
* Currently, the idea is store the scene in the stack, but we never know if 
* this would change.
*/
t_scene	*scene_storage(t_scene *storage)
{
	static t_scene	*scene = NULL;	

	if (!storage && !scene)
		return (NULL);
	if (storage)
		scene = storage;
	return (scene);
}

