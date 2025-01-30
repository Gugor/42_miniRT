/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-shapes-calculations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:37 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/20 17:02 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape-maths.h"
#include "vectors.h"
#include "ray.h"
#include "lights.h"

/**
 * @brief
 * Plane acuation a(x−x0​)+b(y−y0​)+c(z−z0​)=0 
 * t=−(n⋅(O−P0​)/m​⋅d)
 * n = normal
 * d = ray direction
 * P = 
 */
int	hit_plane(void *shp, const t_ray *ray, t_interval *ray_limits,
	t_hit_data *rec)
{
	t_plane		*pl;
	t_sph_hit	hitd;
	double		denominator;
	double		t;

	pl = (t_plane *)shp;
	denominator = dot(&pl->axis, &ray->direction);
	if (fabs(denominator) < 1e-160)
		return (0);
	hitd.oc = sub_v3(pl->pos, ray->origin);
	t = (dot(&pl->axis, &hitd.oc)) / denominator;
	if (!interval_surrounds(ray_limits, t))
		return (0);
	rec->t = t;
	rec->shape_pos = pl->pos;
	rec->rgb = pl->rgb;
	rec->orgb = pl->rgb;
	rec->hit = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	rec->normal = pl->axis;
	set_face_normal(ray, &rec->normal, rec);
	return (1);
}

/**
 * @brief It verifies if a given ray intersects with the given sphere
 *	- a = Represents the quadratic coefficient of the quadratic equation that
 *	describes the ray's intersection with the sphere.
 *	Mathematically, it is equal to the squared magnitude of the ray's
 *	direction vector.
 *	- b = Is the linear term of the quadratic equation. Represents the dot
 *	product between the ray direction (dd) and the vector from the ray's
 *	origin (oo) to the sphere's center (ococ): h=d⋅oc.
 *	- h = Represents the constant term of the quadratic equation.
 *	It is the squared magnitude of the ococ vector minus the sphere's
 *	radius squared (r2r2).
 *	- discriminant = where oc=center−ooc=center−o (the vector from the ray's
 *	origin to the sphere's center) and rr is the sphere's radius.
 *	It has 3 different states: < 0 no hit, 0 one hit(tangent), > 0 2-hits
 *  (travese the sphere). 	 
*/
int	hit_sphere(void *shp, const t_ray *ray, t_interval *ray_limits,
	t_hit_data *rec)
{
	t_sph_hit	hit;
	t_sphere	*s;
	double		sqrtd;
	double		root;

	s = (t_sphere *)shp;
	hit.oc = sub_v3(s->pos, ray->origin);
	hit.a =  length_v3(ray->direction) * length_v3(ray->direction);
	hit.h = dot(&ray->direction, &hit.oc);
	hit.c = length_v3(hit.oc) * length_v3(hit.oc) - s->rad * s->rad;
	hit.discriminant = hit.h * hit.h - hit.a * hit.c;
	if (hit.discriminant < 0)
		return (0);
	sqrtd = sqrt(hit.discriminant); 	
	root = (hit.h - sqrtd) / hit.a;
	if (!interval_surrounds(ray_limits, root))
	{
		root = (hit.h + sqrtd) / hit.a;
		if (!interval_surrounds(ray_limits, root))
			return (0);
	}
	rec->t = root;
	rec->shape_pos = s->pos;
	rec->hit = at((t_ray *)ray, rec->t);
	rec->rgb = s->rgb;
	rec->orgb = s->rgb;
	rec->type = 3;
	rec->normal = div_v3_dbl(sub_v3(rec->hit, s->pos), s->rad);
	// rec->out_normal = normalize_v3(sub_v3(rec->hit, s->pos));
	set_face_normal(ray, &rec->normal, rec);
	return (1);
}


/**
 * @brief 
 * Cylinder tube ∥P−P0​−((P−P0​)⋅v)v∥2=r2
 * 
 */
static int intersect_lateral(const t_cylinder *cyl, const t_ray *ray, t_cyl_hit *hitd, t_hit_data *rec, t_interval *ray_limits)
{
    t_vec3 oc = sub_v3(ray->origin, cyl->pos);
    t_vec3 d_proj = sub_v3(ray->direction, scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
    t_vec3 oc_proj = sub_v3(oc, scale_v3(cyl->axis, dot(&oc, &cyl->axis)));
    hitd->a = dot(&d_proj, &d_proj);
    hitd->h = 2.0 * dot(&d_proj, &oc_proj);
    hitd->c = dot(&oc_proj, &oc_proj) - cyl->size.x * cyl->size.x;
    hitd->discriminant = hitd->h * hitd->h - 4 * hitd->a * hitd->c;

    if (hitd->discriminant < 0)
        return (0);

    double sqrtd = sqrt(hitd->discriminant);
    double root = (-hitd->h - sqrtd) / (2.0 * hitd->a);
    if (!interval_surrounds(ray_limits, root)) {
        root = (-hitd->h + sqrtd) / (2.0 * hitd->a);
        if (!interval_surrounds(ray_limits, root))
            return (0);
    }

    rec->t = root;
    return (1);
}

static int validate_lateral_hit(const t_cylinder *cyl, const t_ray *ray, t_hit_data *rec) {
	t_vec3	point;
	t_vec3	pp;
	double	height_proj;
	t_vec3	temp;

	point = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	pp = sub_v3(point, cyl->pos);
	height_proj = dot(&pp, &cyl->axis);
	if (height_proj < -cyl->size.z || height_proj >= cyl->size.z)
	    return (0);

	rec->hit = point;
	rec->shape_pos = cyl->pos;
	temp = sub_v3(pp, cyl->axis);
	temp = normalize_v3(temp);
	set_face_normal(ray, &temp, rec);
	return (1);
}

static t_vec3 calculate_base(const t_cylinder *cyl, double height_offset) {
    return sum_v3(cyl->pos, scale_v3(cyl->axis, height_offset));
}

static int intersect_base(t_cylinder *cyl, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec, t_vec3 *disk) {
	t_vec3	oc;
	t_vec3 p;
	double t; 
    double denom;
	
	denom = dot(&cyl->axis, &ray->direction);
    if (fabs(denom) < 1e-6) // El rayo es paralelo a la base
        return (0);
    oc = sub_v3( *disk, ray->origin);
    t = dot(&oc, &cyl->axis) / denom;
    if (!interval_surrounds(ray_limits, t))
        return (0);
    // if (t < ray_limits->min || t > ray_limits->max)
    //     return (0);
    p = sum_v3(ray->origin, scale_v3(ray->direction, t));
    if (length_v3(sub_v3(p, *disk)) >= cyl->size.x)
        return (0);
    rec->t = t;
    rec->hit = p;
    set_face_normal(ray, &cyl->axis, rec);
    return (1);
}


/**
 * @brief It calculate the intersection of a ray into a cylinder.
 * `**NOTE: size.z in the cylinder stores the half of th height of the cylinder.**` 
*/
int hit_cylinder(void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec) 
{
	t_cylinder *cyl;
	t_cyl_hit hitd;
	t_vec3 disk;
	t_hit_data temp;
	int	hit_any;

	cyl = (t_cylinder *)shp;
	rec->rgb = cyl->rgb;
	rec->orgb = cyl->rgb;
	hit_any = 0;
	temp = *rec;

	if (intersect_lateral(cyl, ray, &hitd, &temp, ray_limits) && validate_lateral_hit(cyl, ray, &temp))
	{
		hit_any = 1;
		*rec = temp;
		ray_limits->max = temp.t;
	}
	disk = calculate_base(cyl, cyl->size.z);
	if (intersect_base(cyl, ray, ray_limits, &temp, &disk))
	{
		hit_any = 1;
		*rec = temp;
		ray_limits->max = temp.t;
	}
	disk = calculate_base(cyl, -cyl->size.z);
	if (intersect_base(cyl, ray, ray_limits, &temp, &disk))
	{
		hit_any = 1;
		*rec = temp;
		ray_limits->max = temp.t;
	}
	return (hit_any);
}


bool hit(const t_ray *ray, t_interval *lim, t_hit_data *rec)
{
	t_scene		*scn;
	t_lst		*shapes;
	t_hit_data	hitd;
	double		closest;
	bool		hit_anything;

	hit_anything = false;
	scn = get_scene();
	shapes = scn->shapes;
	closest = lim->max;
	while (shapes)
	{
		init_limits(lim, lim->min, closest);
		if (scn->check_hit[shapes->type - SHAPE_TYPE_OFFSET]((void *)shapes->cnt, ray, (t_interval *)lim, &hitd))
		{
			hit_anything = true;
			if (closest > hitd.t)
			{			 
				closest = hitd.t;
				*rec = hitd;
			}
		}
		shapes = shapes->next;
	}
	return (hit_anything);
}
