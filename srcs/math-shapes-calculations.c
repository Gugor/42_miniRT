
#include "shapes.h"
#include "shape-maths.h"
#include "vectors.h"
#include "ray.h"

/**
 * @brief 
 */
int in_plane (t_plane *pl, t_vec3 *p)
{
	//Fake calculations
	(void)p;
	(void)pl;
	return (0);
}

/**
 * @brief [x2+y2+z2=r2]
 * bool hit_sphere(const point3& center, double radius, const ray& r) {
    vec3 oc = center - r.origin();
    auto a = dot(r.direction(), r.direction());
    auto b = -2.0 * dot(r.direction(), oc);
    auto c = dot(oc, oc) - radius*radius;
    auto discriminant = b*b - 4*a*c;
	    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-b - std::sqrt(discriminant) ) / (2.0*a);
    }
 *}
 */
int in_sphere (const t_p3 *center, double r, const t_ray *ray)
{
	t_vec3 oc;
	double a;
	double b;
	double c;
	double discriminant;

	oc = rest_v3((t_vec3 *)&center, (t_vec3 *)&ray->origin);	
	a = dot(&ray->direction, &ray->direction);
	b = -2.0 * dot(&ray->direction, &oc);
	c = dot(&oc, &oc) - r * r;
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
}

/**
 * @brief [x2+y2+z2=r2]
 */
int in_cylinder (t_cylinder *cy, t_vec3 *p)
{
	//Fake calculations
	(void)p;
	(void)cy;
	return (0);
}

