

#ifndef REDERING_SCENE_H
# define REDNERING_SCENE_H

#include "scene.h"

void		render_scene(t_scene *scene);
t_vec3		get_pix_center(t_vec3 *pix00, t_vec3 *dlt_u, t_vec3 *dlt_v, int indx[2]);


#endif