

#include "ray.h"
#include "shapes.h"
#include "shape-maths.h"

// Sets the hit record normal vector.
// NOTE: the parameter `outward_normal` is assumed to have unit length.
void set_face_normal(const t_ray *r, const t_vec3 *outward_normal, t_hit_data *hitd)
{
        hitd->is_front = dot(r-direction(), outward_normal) < 0;
        hitd->normal = front_face ? outward_normal : -outward_normal;
}