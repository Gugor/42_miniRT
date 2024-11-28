
#include "vectors.h"

double dot(const t_vec3 *v1, const t_vec3 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v1->z));
}

t_vec3 cross(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3 new;

	new.x = (v1->y * v2->z - v1->z * v2->y);
	new.y = (v1->z * v2->x - v1->x * v2->z);
	new.z = (v1->x * v2->y - v1->y * v2->x);
	return (new);
}