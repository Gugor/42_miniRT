
#ifndef RAY_H
# define RAY_H

#include "vectors.h"

typedef struct s_ray
{
	t_p3 	origin;
	t_vec3	direction;
	t_color	rgb;
	double	size;
	double	(*cast)(struct s_ray *ray);
}	t_ray;

#endif