

#include "ray.h"
#include "vectors.h"
#include "colours.h"

/**
 * @brief It cast a ray from an origin in a direction with a size. 
 * The formula for casting the ray is: P(t)=A+tb where A = Origing b = Direction
 * and t = size
 */
double cast_ray(t_ray *ray)
{
	if (!ray)
		return (0);
	return (1);
}

t_color ray_color(const t_ray *r)
{
    t_vec3 norm;
	double a;
	t_vec3 res;
	t_vec3 res2;
	
	norm = (*r).norm;
    a = 0.5 * ( norm.y + 1.0);
	res = r->direction;
	res.x = (1.0 - a) * 255;	
	res.y = (1.0 - a) * 255;	
	res.z = (1.0 - a) * 255;	
	res2.x = a * (255 * 0.5);
	res2.y = a * (255 * 0.7);
	res2.y = a * 255;
	res = sum_v3(&res, &res2);
	return (vec3_to_rgb(&res));
}

/**
 * @brief It updates the direction of a ray
 *
void update_ray(t_ray *r, t_vec3 *dir)
{
	*r = init_ray((t_vec3)&r->origin, dir);
}
*/

/**
 * @brief It creates a ray from an origin with a direction.
 */
t_ray  init_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray ray;
	ray.origin = *origin;
	ray.direction = *dir;
	ray.ray = rest_v3(dir, origin);
	ray.mag = length_v3(&ray.ray);
	ray.norm = normalize_v3(&ray.ray);
	return (ray);
}