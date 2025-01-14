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
	float		denominator;
	float		t;

	pl = (t_plane *)shp;
	denominator = dot(&pl->axis, &ray->direction);
	if (fabs(denominator) < 1e-6)
		return (0);
	hitd.oc = sub_v3(ray->origin, pl->pos);
	t = -(dot(&pl->axis, &hitd.oc)) / denominator;
	if (!interval_surroundss(ray_limits, t))
		return (0);
	rec->t = t;
	rec->rgb = pl->rgb;
	rec->hit = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	rec->out_normal = pl->axis;
	set_face_normal(ray, &rec->out_normal, rec);
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
	float		sqrtd;
	float		root;

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
	if (!interval_surroundss(ray_limits, root))
	{
		root = (hit.h + sqrtd) / hit.a;
		if (!interval_surroundss(ray_limits, root))
			return (0);
	}
	rec->t = root;
	rec->hit = at((t_ray *)ray, rec->t);
	rec->rgb = s->rgb;
	rec->out_normal = div_v3_dbl(sub_v3(rec->hit, s->pos), s->rad);
	set_face_normal(ray, &rec->out_normal, rec);
	return (1);
}


/**
 * @brief 
 * Cylinder tube ∥P−P0​−((P−P0​)⋅v)v∥2=r2
 * 
 */
/*
int	hit_cylinder (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{	
	t_cylinder	*cyl;
	t_cyl_hit	hitd;
	float		sqrtd;
	float		root1;
	float		root2;

	(void)ray_limits;

	cyl = (t_cylinder *)shp;
	hitd.oc =  sub_v3(ray->origin, cyl->pos);
	hitd.d_proj = sub_v3(ray->direction, scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
	hitd.oc_proj = sub_v3(hitd.oc, scale_v3(cyl->axis, dot(&hitd.oc, &cyl->axis)));
	hitd.a = dot(&hitd.d_proj, &hitd.d_proj);
	hitd.h = 2.0 * dot(&hitd.d_proj, &hitd.oc_proj);
	hitd.c = dot(&hitd.oc_proj, &hitd.oc_proj) - cyl->size.x * cyl->size.x;
	hitd.discriminant = hitd.h * hitd.h - 4 * hitd.a * hitd.c;
	if (hitd.discriminant < 0)
		return (0);

	printf("Hit Cylinder\n");
	sqrtd = sqrt(hitd.discriminant);
	root1 = (-hitd.h - sqrtd) / (2.0 * hitd.a);
	root2 = (-hitd.h + sqrtd) / (2.0 * hitd.a);
	rec->t = root1;
	if (rec->t < 0 || rec->t > root2)
		rec->t = root2;
	if (rec->t < 0)
		return (0);
	t_vec3 point = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	t_vec3 pp = sum_v3(point, cyl->pos);
	double height_proj = dot(&pp, &cyl->axis);
	if (height_proj < 0 || height_proj > cyl->size.y)
		return (0);
	rec->hit = point;
	rec->out_normal = sum_v3(point, sum_v3(cyl->pos, scale_v3(cyl->axis, height_proj)));
	set_face_normal(ray, &rec->out_normal, rec);
	return (1);
}
*/
/*
int	hit_cylinder (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{	
	t_cylinder	*cyl;
	t_cyl_hit	hitd;
	float		sqrtd;
	float		root;
	cyl = (t_cylinder *)shp;
	hitd.oc = sub_v3(ray->origin, cyl->pos);
	hitd.d_proj = sub_v3(ray->direction, scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
	hitd.oc_proj = sub_v3(hitd.oc, scale_v3(cyl->axis, dot(&hitd.oc, &cyl->axis)));
	hitd.a = dot(&hitd.d_proj, &hitd.d_proj);
	hitd.h = 2.0 * dot(&hitd.d_proj, &hitd.oc_proj);
	hitd.c = dot(&hitd.oc_proj, &hitd.oc_proj) - cyl->size.x * cyl->size.x;
	hitd.discriminant = hitd.h * hitd.h - 4 * hitd.a * hitd.c;
	if (hitd.discriminant < 0)
		return (0);

	sqrtd = sqrt(hitd.discriminant);
	root = (-hitd.h - sqrtd) / (2.0 * hitd.a);
	if (!interval_surroundss(ray_limits, root))
	{
		root = (-hitd.h + sqrtd) / (2.0 * hitd.a);
		if (!interval_surroundss(ray_limits, root))
			return (0);
	}
	rec->t = root;
	t_vec3 point = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	t_vec3 pp = sub_v3(point, cyl->pos);
	double height_proj = dot(&pp, &cyl->axis);
	if (height_proj < 0 || height_proj > cyl->size.y)
		return (0);

	t_vec3 temp = sub_v3(point, cyl->pos);
	temp = sub_v3(temp, scale_v3(cyl->axis, height_proj));
	rec->out_normal = normalize_v3(temp);
	set_face_normal(ray, &rec->out_normal, rec);
	rec->hit = point;

	return (1);
}
*/
/*
int hit_cylinder(void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{
	t_cylinder *cyl;
	t_cyl_hit hitd;
	float sqrtd;
	float root;

	cyl = (t_cylinder *)shp;
	hitd.oc = sub_v3(ray->origin, cyl->pos);
	hitd.d_proj = sub_v3(ray->direction, scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
	hitd.oc_proj = sub_v3(hitd.oc, scale_v3(cyl->axis, dot(&hitd.oc, &cyl->axis)));
	hitd.a = dot(&hitd.d_proj, &hitd.d_proj);
	hitd.h = 2.0 * dot(&hitd.d_proj, &hitd.oc_proj);
	hitd.c = dot(&hitd.oc_proj, &hitd.oc_proj) - cyl->size.x * cyl->size.x;
	hitd.discriminant = hitd.h * hitd.h - 4 * hitd.a * hitd.c;

	if (hitd.discriminant < 0)
		return (0);

	sqrtd = sqrt(hitd.discriminant);
	root = (-hitd.h - sqrtd) / (2.0 * hitd.a);
	if (!interval_surroundss(ray_limits, root)) {
		root = (-hitd.h + sqrtd) / (2.0 * hitd.a);
		if (!interval_surroundss(ray_limits, root))
			return (0);
	}

	rec->t = root;
	t_vec3 point = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	t_vec3 pp = sub_v3(point, cyl->pos);
	double height_proj = dot(&pp, &cyl->axis);

	// Check if the point is within the height of the cylinder
	if (height_proj < 0 || height_proj > cyl->size.y) 
	{
		// Check intersection with base caps if the cylinder is closed
		t_vec3 top_center = sum_v3(cyl->pos, scale_v3(cyl->axis, cyl->size.y));

		// Base intersection (lower disk)
		double t_base;
		t_vec3 pos_minus_origin = sub_v3(cyl->pos, ray->origin);
		t_base = dot(&pos_minus_origin, &cyl->axis);
		t_base = t_base / dot(&ray->direction, &cyl->axis);
		t_vec3 base_point = sum_v3(ray->origin, scale_v3(ray->direction, t_base));
		if (t_base >= ray_limits->min && t_base <= ray_limits->max &&
			normalize_v3(sub_v3(base_point, cyl->pos)).x <= cyl->size.x) 
			{
			rec->t = t_base;
			rec->out_normal = scale_v3(cyl->axis, -1); // Normal points outward
			rec->hit = base_point;
			return (1);
		}

		// Top intersection (upper disk)
		pos_minus_origin = sub_v3(cyl->pos, ray->origin);
		t_base = dot(&pos_minus_origin, &cyl->axis);
		t_base = t_base / dot(&ray->direction, &cyl->axis);
		base_point = sum_v3(ray->origin, scale_v3(ray->direction, t_base));
		if (t_base >= ray_limits->min && t_base <= ray_limits->max &&
			normalize_v3(sub_v3(base_point, top_center)).x <= cyl->size.x) {
			rec->t = t_base;
			rec->out_normal = cyl->axis; // Normal points outward
			rec->hit = base_point;
			return (1);
		}

		return (0);
	}

	// Handle intersection with the lateral surface
	t_vec3 temp = sub_v3(point, cyl->pos);
	temp = sub_v3(temp, scale_v3(cyl->axis, height_proj));
	rec->out_normal = normalize_v3(temp);
	set_face_normal(ray, &rec->out_normal, rec);
	rec->hit = point;

	return (1);
}
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

    float sqrtd = sqrt(hitd->discriminant);
    float root = (-hitd->h - sqrtd) / (2.0 * hitd->a);
    if (!interval_surroundss(ray_limits, root)) {
        root = (-hitd->h + sqrtd) / (2.0 * hitd->a);
        if (!interval_surroundss(ray_limits, root))
            return (0);
    }

    rec->t = root;
    return (1);
}

static int validate_lateral_hit(const t_cylinder *cyl, const t_ray *ray, t_hit_data *rec) {
	t_vec3 point;
	t_vec3 pp;
	double height_proj;
	t_vec3 temp;

	point = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	pp = sub_v3(point, cyl->pos);
	height_proj = dot(&pp, &cyl->axis);
	if (height_proj < 0.5 *(-cyl->size.y) || height_proj >= 0.5 * cyl->size.y)
	    return (0);

	rec->hit = point;
	temp = sub_v3(pp, scale_v3(cyl->axis, height_proj));
	set_face_normal(ray, &temp, rec);
	return (1);
}

static t_vec3 calculate_base(const t_cylinder *cyl, float height_offset) {
    return sum_v3(cyl->pos, scale_v3(cyl->axis, height_offset));
}

static int intersect_base(t_cylinder *cyl, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec, t_vec3 *disk) {
	t_vec3	oc;
	t_vec3 p;
	float t; 

    float denom = dot(&cyl->axis, &ray->direction);
    if (fabs(denom) < 1e-6) // El rayo es paralelo a la base
        return (0);
    oc = sub_v3(ray->origin, *disk);
    t = -dot(&oc, &cyl->axis) / denom;
    if (t < ray_limits->min || t > ray_limits->max)
        return (0);
    p = sum_v3(ray->origin, scale_v3(ray->direction, t));
    if (length_v3(sub_v3(p, *disk)) >= cyl->size.x)
        return (0);
    rec->t = t;
    rec->hit = p;
    set_face_normal(ray, &cyl->axis, rec);
    return (1);
}

int hit_cylinder(void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec) 
{
	t_cylinder *cyl;
	t_cyl_hit hitd;
	t_vec3 disk;
	t_hit_data temp;
	int	hit_any;

	cyl = (t_cylinder *)shp;
	rec->rgb = cyl->rgb;
	hit_any = 0;
	temp = *rec;
	// Intersección con la superficie lateral
	if (intersect_lateral(cyl, ray, &hitd, &temp, ray_limits) && validate_lateral_hit(cyl, ray, &temp))
	{
		hit_any = 1;
		if (temp.t < rec->t)
		{}
		rec->t = temp.t;
		ray_limits->max = temp.t;
	}

	
	// // Intersección con la base superior
	disk = calculate_base(cyl, 0.5 * cyl->size.y);
	// printf("	Disk: [%f,%f,%f]\n", disk.x, disk.y, disk.z);
	// disk = vec3(0, 0, -3);
	if (intersect_base(cyl, ray, ray_limits, &temp, &disk))
	{
		hit_any = 1;
		if (temp.t < rec->t)
		{
		}
			*rec = temp;
			ray_limits->max = temp.t;
	}


	// // Intersección con la base inferior
	disk = calculate_base(cyl, -0.5 * (cyl->size.y));
	if (intersect_base(cyl, ray, ray_limits, &temp, &disk))
	{
		hit_any = 1;
		if (temp.t < rec->t)
		{
		}
			*rec = temp;
			ray_limits->max = temp.t;
	}
	return (hit_any);
}

/*int hit_cylinder(void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{
	t_cylinder *cyl;
	t_cyl_hit hitd;

	t_vec3 diff; // Variables temporales para evitar problemas con dot()

	cyl = (t_cylinder *)shp;



	// Intersección con las tapas:
	float root_cap;

	// Tapa inferior
	float denom = dot(&ray->direction, &cyl->axis);
	if (fabs(denom) > 1e-6) 
	{
		t_vec3 oc = sub_v3(cyl->pos, ray->origin); 
		root_cap = dot(&oc, &cyl->axis) / denom;
		if (interval_surroundss(ray_limits, root_cap)) {
			t_vec3 hit_point_cap = sum_v3(ray->origin, scale_v3(ray->direction, root_cap));
			diff = sub_v3(hit_point_cap, cyl->pos);
			if (dot(&diff, &diff) <= cyl->size.x * cyl->size.x) {
				if (rec->t > root_cap || rec->t < 0)
				{
					rec->t = root_cap;
					rec->hit = hit_point_cap;
					rec->out_normal = scale_v3(cyl->axis, -1.0f);
					set_face_normal(ray, &rec->out_normal, rec);
				}
			}
		}
	}

	// Tapa superior
	t_vec3 top_center = sum_v3(cyl->pos, scale_v3(cyl->axis, cyl->size.y));
	denom = dot(&ray->direction, &cyl->axis);
	if (fabs(denom) > 1e-6)
	{
		t_vec3 oc = sub_v3(top_center, ray->origin);
		root_cap = dot(&oc, &cyl->axis) / denom;
		if (interval_surroundss(ray_limits, root_cap)) {
			t_vec3 hit_point_cap = sum_v3(ray->origin, scale_v3(ray->direction, root_cap));
			diff = sub_v3(hit_point_cap, top_center);
			if (dot(&diff, &diff) <= cyl->size.x * cyl->size.x) {
				if (rec->t > root_cap || rec->t < 0)
				{
					rec->t = root_cap;
					rec->hit = hit_point_cap;
					rec->out_normal = cyl->axis;
					set_face_normal(ray, &rec->out_normal, rec);
				}
			}
		}
	}
	return (1);
}*/


bool hit(const t_ray *ray, t_interval *lim, t_hit_data *rec)
{
	t_scene		*scn;
	t_lst		*shapes;
	t_hit_data	hitd;
	float		closest;
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
