
#ifndef RAY_H
# define RAY_H

#include "vectors.h"

typedef struct s_ray
{
	t_p3 		origin;
	t_vec3		direction;
	t_vec3		ray;
	t_color	rgb;
	double		mag;
	t_vec3		norm;
	double	(*cast)(struct s_ray *ray);
}	t_ray;

/*							Ray Casting								  */
t_ray  			init_ray(t_vec3 *origin, t_vec3 *dir);
t_color			ray_color(const t_ray *r);
double			cast_ray(t_ray *ray);
t_vec3			lookat(t_ray *r, double t);

#endif