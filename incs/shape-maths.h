

#ifndef SHAPE_MATHS_H
# define SHAPE_MATHS_H

# include "shapes.h"
# include "ray.h"
# include "vectors.h"

typedef struct s_spheric_hit
{
	t_vec3 oc;
	double a;
	double h;
	double c;
	double discriminant;

}	t_sph_hit;

int			hit_plane (void *shp, const t_ray *ray, double ray_limits[2], t_hit_data *rec);
double		tst_hit_sphere (const t_p3 *p, double r, const t_ray *ray);
int 		hit_sphere (void *shp, const t_ray *ray, double ray_limits[2], t_hit_data *rec);
int			hit_cylinder (void *shp, const t_ray *ray, double ray_limits[2], t_hit_data *rec);
#endif