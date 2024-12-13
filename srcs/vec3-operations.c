
#include "vectors.h"

t_vec3 vec3(double x, double y, double z)
{
	t_vec3 v3;
	v3.x = x;
	v3.y = y;
	v3.z = z;
	return (v3);
}

t_vec3		mult_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 new;
	new.x = v1.x * v2.x;
	new.y = v1.y * v2.y;
	new.z = v1.z * v2.z;
	return (new);
}

t_vec3		div_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 new;
	new.x = v1.x / v2.x;
	new.y = v1.y / v2.y;
	new.z = v1.z / v2.z;
	return (new);
}

t_vec3		sum_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 new;
	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vec3		rest_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3 new;
	// printf("		::V1[%f,%f,%f] - V2[%f,%f,%f]\n", v1->x, v1->y, v1->z, v2->x, v2->y, v2->z);
	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}
//return ((double)(v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
