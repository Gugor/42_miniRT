

#include "ray.h"
#include "maths.h"
#include "vectors.h"
#include "colours.h"
#include "shapes.h"
#include "shape-maths.h"

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

t_color tst_ray_color(const t_ray *r)
{
    t_vec3 norm;
	t_p3	sp;
	t_color res;
	double	t;
	
	sp.x = 0;
	sp.y = 0;
	sp.z = -1;
	t = tst_hit_sphere((void *)&sp, 0.5, r) >= 0;
	if (t > 0.0)
	{
		t_vec3 sdet = at((t_ray *)r, t);
		t_vec3 rest = rest_v3(sdet, sp);
		t_vec3 N = normalize_v3(rest);
		t_color c;
		c = scale_rgb((N.x + 1) * 0.5, (N.y + 1) * 0.5, (N.z + 1) * 0.5);
		//c.clr = (uint8_t)(255.999 * ((N.x + 1) * 0.5)) << 16 | (uint8_t)(255.999 * ((N.y + 1) * 0.5)) << 8 | (uint8_t)(255.999 * ((N.z + 1) * 0.5));
        return (c);
	}
	norm = (*r).norm;
	printf("=> Ray[%f] Norm[%f,%f,%f]\n", r->mag, norm.x, norm.y, norm.z);
	res.clr = lerpRGB(norm.y, scale_rgb(1.0, 1.0,1.0), scale_rgb(0.5, 0.7, 1.0));
	printf("	::A [%f]RGB[%u,%u,%u][%i]\n", norm.y, (res.clr >> 16) & 0xFF, (res.clr >> 8) & 0xFF , res.clr & 0xFF, res.clr);
	return (res);

}

t_color ray_color(const t_ray *ray, void *shp, t_entid type)
{
	t_scene		*scn;
	t_vec3		pos;
	t_hit_data	hitd;
	int			hit;

	hit = 0;
	scn = get_scene();
	init_limits((t_interval *)&ray->lim, 0, INFINITY);
	get_SHP_pos(&pos, shp, type);
	hit = scn->check_hit[type](shp, ray, (t_interval *)&ray->lim, &hitd);
	if (hit)
	{
		printf("====== Hit shape: %i\n", type);
		// hitd.det = at((t_ray*)ray, hitd.t);
		// hitd.trans = rest_v3(hitd.det, pos);
		// hitd.N = normalize_v3(hitd.trans);
		hitd.rgb = scale_rgb((hitd.normal.x + 1) * 0.5, (hitd.normal.y + 1) * 0.5, (hitd.normal.z + 1) * 0.5);
		return (hitd.rgb);
	}
	hitd.normal = (*ray).norm;
	printf("=> Ray[%f] Norm[%f,%f,%f]\n", ray->mag, hitd.normal.x, hitd.normal.y, hitd.normal.z);
	hitd.rgb.clr = lerpRGB(hitd.normal.y, scale_rgb(1.0, 1.0,1.0), scale_rgb(0.5, 0.7, 1.0));
	printf("	::A [%f]RGB[%u,%u,%u][%i]\n", hitd.normal.y, (hitd.rgb.clr >> 16) & 0xFF, (hitd.rgb.clr >> 8) & 0xFF , hitd.rgb.clr & 0xFF, hitd.rgb.clr);
	return (hitd.rgb);
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
 * @brief It finds a a point in a ray. T is a scalar that set the distance
 * to scale form origin.
 */
t_vec3			at(t_ray *r, double t)
{
	t_vec3 dt;
	dt = mult_v3_dbl(r->direction, t);
	return (rest_v3(r->origin, dt));
}

/**
 * @brief It creates a ray from an origin with a direction.
 */
t_ray  init_ray(t_vec3 *origin, t_vec3 *dir)
{
	t_ray ray;
	printf("=> Init ray:\n");
	ray.origin = *origin;
	printf("	::or[%f,%f,%f]\n ", ray.origin.x, ray.origin.y, ray.origin.z);
	ray.direction = *dir;
	printf("	::dir[%f,%f,%f]\n", ray.direction.x, ray.direction.y, ray.direction.z);
	ray.ray = rest_v3(*dir, *origin);
	ray.mag = length_v3(ray.ray);
	ray.norm = normalize_v3(ray.ray);
	return (ray);
}