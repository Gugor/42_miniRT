

#ifndef SHAPE_MATHS_H
# define SHAPE_MATHS_H

# include <stdbool.h>
# include "shapes.h"
# include "ray.h"
# include "vectors.h"

typedef struct s_ray t_ray;
// typedef struct s_hit_data t_hit_data;
typedef struct s_cylinder t_cylinder;

typedef struct s_spheric_hit
{
	t_vec3	oc;
	double	a;
	double	h;
	double	c;
	double	discriminant;
	int		is_front;
	t_vec3	normal;
}	t_sph_hit;

typedef struct s_cylinder_hit
{
	t_vec3	oc;             // Vector from ray origin to cylinder center (ray.origin - cylinder.origin)
	double	a;              // Quadratic term coefficient (related to ray.direction and cylinder axis)
	double	h;              // Scalar value for the ray's parameter t along the projected direction
	double	c;              // Constant term in the quadratic equation
	double	discriminant;   // Discriminant of the quadratic equation (used to determine intersection)
	int		is_front;       // Boolean indicating whether the intersection is on the front face of the cylinder
	t_vec3	d_proj;         // Projection of ray direction onto the cylinder's axis
	t_vec3	oc_proj;        // Projection of `oc` (ray origin to cylinder center) onto the cylinder's axis
	t_vec3	normal;         // Surface normal at the point of intersection
}	t_cyl_hit;


int			hit_plane (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
double		tst_hit_sphere (const t_p3 *p, double r, const t_ray *ray);
int 		hit_sphere (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
int			hit_cylinder (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
int 		hit_caps(t_cylinder *cyl, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
bool		hit(const t_ray *ray, t_interval *lim, t_hit_data *rec);
#endif