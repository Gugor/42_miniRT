

#ifndef SHAPE_MATHS_H
# define SHAPE_MATHS_H

# include "shapes.h"
# include "ray.h"
# include "vectors.h"

int		in_plane (t_plane *pl, t_vec3 *p);
int			in_sphere (const t_p3 *p, double r, const t_ray *ray);
int		in_cylinder (t_cylinder *cy, t_vec3 *p);
#endif