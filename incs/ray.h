
#ifndef RAY_H
# define RAY_H

# include "entity-data.h"
# include "vectors.h"
# include "maths.h"
# include "window.h"


typedef struct s_window	t_window;
typedef struct s_lst	t_lst;

typedef struct s_hit_data
{
	double	t;
	int		is_front;
	int		id;
	t_p3	hit;
	t_vec3	shape_pos;
	t_vec3	normal;
	t_vec3	det;
	t_color	rgb;
	t_color	orgb;
	t_entid	type;
}	t_hit_data;

typedef struct s_ray
{
	t_p3		origin;
	t_vec3		direction;
	t_vec3		ray;
	t_color		rgb;
	double		length;
	t_vec3		norm;
	t_interval	lim;
}	t_ray;

/*							Ray Casting								  */
t_ray			init_ray(t_vec3 *origin, t_vec3 *dir, double min, double max);
t_color			ray_color(const t_ray *r, long max_depth);
t_ray			get_ray(t_window *win, t_camera *camera, t_ivec2 *pix_pos);
t_vec3			at(t_ray *r, double t);

#endif