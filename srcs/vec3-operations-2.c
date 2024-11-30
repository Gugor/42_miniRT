

#include "vectors.h"

double sqr_v3(t_vec3 *v3)
{
	return (v3->x * v3->x + v3->y * v3->y + v3->z * v3->z);
}