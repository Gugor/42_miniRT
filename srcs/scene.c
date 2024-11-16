
#include "scene.h"

/**
* @brief It gets the scene stored statically by `scene_storage()`.
* @returns `{t_scene *}`
*/
t_scene *get_scene()
{
	return (scene_storage(NULL));
}

/**
* @brief It stores statically the scene object, te be retrieved when needed.
* @param `{t_scene *}` a pointer to the scene data strcuture.
* @returns `{t_scene *}`
* `a scene`
* `NULL if it no scene has been stored`
* NOTE: this function does not allocates memory it just stores a pointer to memory.
* so be aware where this memory is allocate and take messures in case you need to manually free it.
* Currently, the idea is store the scene in the stack, but we never know if this would change.
*/
t_scene *scene_storage(t_scene *storage)
{
	static t_scene *scene = NULL;	
	
	if (!storage && !scene)
		return (NULL);
	if (storage)
		scene = storage;
	return (scene);
}

