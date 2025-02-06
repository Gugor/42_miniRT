/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-shape-calculations-cylinder.c                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:59:03 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/06 18:59:06 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape-maths.h"
#include "vectors.h"
#include "ray.h"
#include "lights.h"

/**
 * @brief 
 * Cylinder tube ∥P−P0​−((P−P0​)⋅v)v∥2=r2
 * 
 */
static int	intersect_lateral(const t_cylinder *cyl, const t_ray *ray,
		t_hit_data *rec, t_interval *ray_limits)
	{
	t_cyl_hit	hitd;

	hitd.oc = sub_v3(ray->origin, cyl->pos);
	hitd.d_proj = sub_v3(ray->direction,
			scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
	hitd.oc_proj = sub_v3(hitd.oc, scale_v3(cyl->axis,
				dot(&hitd.oc, &cyl->axis)));
	hitd.a = dot(&hitd.d_proj, &hitd.d_proj);
	hitd.h = dot(&hitd.d_proj, &hitd.oc_proj);
	hitd.c = dot(&hitd.oc_proj, &hitd.oc_proj) - cyl->size.x * cyl->size.x;
	hitd.discriminant = hitd.h * hitd.h - hitd.a * hitd.c;
	if (hitd.discriminant < 1e-160)
		return (0);
	hitd.sqrtd = sqrt(hitd.discriminant);
	hitd.root = (-hitd.h - hitd.sqrtd) / (hitd.a);
	if (!interval_surrounds(ray_limits, hitd.root))
	{
		hitd.root = (-hitd.h + hitd.sqrtd) / (hitd.a);
		if (!interval_surrounds(ray_limits, hitd.root))
			return (0);
	}
	rec->t = hitd.root;
	return (1);
}

static int	validate_lateral_hit(const t_cylinder *cyl,
	const t_ray *ray, t_hit_data *rec)
{
	t_vec3	pp;
	double	height_proj;
	t_vec3	temp;

	rec->hit = at((t_ray *)ray, rec->t);
	pp = sub_v3(rec->hit, cyl->pos);
	height_proj = dot(&pp, &cyl->axis);
	if (height_proj < -cyl->size.z || height_proj >= cyl->size.z)
		return (0);
	rec->shape_pos = cyl->pos;
	temp = sub_v3(cyl->pos, rec->hit);
	temp = normalize_v3(sub_v3(scale_v3(cyl->axis,
					dot(&temp, &cyl->axis)), temp));
	set_face_normal(ray, &temp, rec);
	return (1);
}

static int	intersect_base(t_cylinder *cyl, const t_ray *ray,
	t_interval *ray_limits, t_hit_data *rec)
{
	t_vec3	oc;
	t_vec3	p;
	double	t;
	double	denom;
	t_vec3	disk;

	if (cyl->top)
		disk = sum_v3(cyl->pos, scale_v3(cyl->axis, cyl->size.z));
	else
		disk = sum_v3(cyl->pos, scale_v3(cyl->axis, -cyl->size.z));
	denom = dot(&cyl->axis, &ray->direction);
	if (fabs(denom) < 1e-6)
		return (0);
	oc = sub_v3(disk, ray->origin);
	t = dot(&oc, &cyl->axis) / denom;
	if (!interval_surrounds(ray_limits, t))
		return (0);
	p = sum_v3(ray->origin, scale_v3(ray->direction, t));
	if (length_v3(sub_v3(p, disk)) >= cyl->size.x)
		return (0);
	rec->t = t;
	rec->hit = p;
	set_face_normal(ray, &cyl->axis, rec);
	return (1);
}

static int	set_hit_cylinder(t_hit_data *rec,
	t_hit_data temp, t_interval *ray_limits)
{
	*rec = temp;
	ray_limits->max = temp.t;
	return (1);
}

/**
 * @brief It calculate the intersection of a ray into a cylinder.
 * `**NOTE: size.z in the cylinder stores the half 
 * of th height of the cylinder.**` 
*/
int	hit_cylinder(void *shp, const t_ray *ray,
	t_interval *ray_limits, t_hit_data *rec)
{
	t_cylinder	*cyl;
	t_hit_data	temp;
	int			hit_any;

	cyl = (t_cylinder *)shp;
	rec->rgb = cyl->rgb;
	rec->orgb = cyl->rgb;
	hit_any = 0;
	temp = *rec;
	cyl->top = 1;
	if (intersect_lateral(cyl, ray, &temp, ray_limits)
		&& validate_lateral_hit(cyl, ray, &temp))
		hit_any = set_hit_cylinder(rec, temp, ray_limits);
	if (intersect_base(cyl, ray, ray_limits, &temp))
		hit_any = set_hit_cylinder(rec, temp, ray_limits);
	cyl->top = 0;
	if (intersect_base(cyl, ray, ray_limits, &temp))
		hit_any = set_hit_cylinder(rec, temp, ray_limits);
	return (hit_any);
}
