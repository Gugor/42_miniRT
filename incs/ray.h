
#ifndef RAY_H
# define RAY_H

# include "entity-data.h"
# include "vectors.h"
# include "maths.h"
# include "window.h"


typedef struct s_window t_window;

typedef struct s_hit_data 
{
	t_p3	hit;
	t_vec3	normal;
	double	t;
	int		is_front;
	t_vec3	det;
	t_vec3	trans;
	t_vec3	N;
	t_color	rgb;
}	t_hit_data;

typedef struct s_ray
{
	t_p3 		origin;
	t_vec3		direction;
	t_vec3		ray;
	t_color		rgb;
	double		length;
	t_vec3		norm;
	t_interval	lim;
	double	(*cast)(struct s_ray *ray);
}	t_ray;

typedef struct s_lst t_lst;
/*							Ray Casting								  */
t_ray  			init_ray(t_vec3 *origin, t_vec3 *dir);
t_color			tst_ray_color(const t_ray *r);
t_color			ray_color(const t_ray *r);
t_ray			get_ray(t_window *win, t_camera *camera, t_ivec2 *pix_pos);
t_vec3			at(t_ray *r, double t);

#endif