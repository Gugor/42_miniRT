
#include "shapes.h"
#include "shape-maths.h"
#include "vectors.h"

/**
 * @brief 
 */
double in_plane (t_plane *pl, t_vec3 *p)
{
	//Fake calculations
	(void)p;
	if(sqr_v3(&pl->pos) <= pl->axis.x)
		return (1);
	return (0);
}

/**
 * @brief [x2+y2+z2=r2]
 */
double in_sphere (t_sphere *sph, t_vec3 *p)
{
	if(sqr_v3(p) <= (sph->size * sph->size))
		return (1);
	return (0);
}

/**
 * @brief [x2+y2+z2=r2]
 */
double in_cylinder (t_cylinder *cy, t_vec3 *p)
{
	//Fake calculations
	(void)p;
	if(sqr_v3(&cy->pos) <= cy->size.x)
		return (1);
	return (0);
}

