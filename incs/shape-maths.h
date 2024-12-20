

#ifndef SHAPE_MATHS_H
# define SHAPE_MATHS_H

# include <stdbool.h>
# include "shapes.h"
# include "ray.h"
# include "vectors.h"

typedef struct s_ray t_ray;
typedef struct s_hit_data t_hit_data;

typedef struct s_spheric_hit
{
	t_vec3	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;
	int		is_front;
	t_vec3	normal;
}	t_sph_hit;

typedef struct s_cylinder_hit
{
	t_vec3	oc;
	float	a;
	float	h;
	float	c;
	float	discriminant;
	int		is_front;
	t_vec3	d_proj;
	t_vec3	oc_proj;
	t_vec3	normal;
}	t_cyl_hit;

int			hit_plane (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
float		tst_hit_sphere (const t_p3 *p, float r, const t_ray *ray);
int 		hit_sphere (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
int			hit_cylinder (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec);
bool		hit(const t_ray *ray, t_interval *lim, t_hit_data *rec);
#endif