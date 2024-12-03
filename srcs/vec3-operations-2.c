

#include "vectors.h"
#include <math.h>

double sqr_v3(t_vec3 *v3)
{
	return (v3->x * v3->x + v3->y * v3->y + v3->z * v3->z);
}

double length_v3(t_vec3 *v3)
{
	return (sqrt(sqr_v3(v3)));
}

t_vec3 normalize_v3(t_vec3 *v3)
{
	return (div_v3_dbl(v3, length_v3(v3)));
}