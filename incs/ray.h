
#ifndef RAY_H
# define RAY_H

#include "entity-data.h"
#include "vectors.h"

typedef struct s_hit_data 
{
	t_p3	hit;
	t_vec3	normal;
	double	t;
	int		is_front;
}	t_hit_data;

typedef struct s_ray
{
	t_p3 		origin;
	t_vec3		direction;
	t_vec3		ray;
	t_color		rgb;
	double		mag;
	t_vec3		norm;
	double	(*cast)(struct s_ray *ray);
}	t_ray;

/*							Ray Casting								  */
t_ray  			init_ray(t_vec3 *origin, t_vec3 *dir);
t_color			tst_ray_color(const t_ray *r);
t_color			ray_color(const t_ray *r, void *shp, t_entid type);
double			cast_ray(t_ray *ray);
t_vec3			at(t_ray *r, double t);

#endif