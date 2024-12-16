

#ifndef RENDERING_SCENE_H
# define RENDERING_SCENE_H

#include "scene.h"

void		render_scene(t_scene *scene);
t_vec3		get_pix_rand_pos(t_vec3 *pix00, t_vec3 *dlt_u, t_vec3 *dlt_v, t_ivec2 *pix_pos);


#endif