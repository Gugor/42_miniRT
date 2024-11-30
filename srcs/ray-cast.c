

#include "ray.h"

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

/**
 * @brief It creates a ray from an origin with a direction.
 */
t_ray  init_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray ray;
	ray.origin = *origin;
	ray.direction = *dir;
	return (ray);
}