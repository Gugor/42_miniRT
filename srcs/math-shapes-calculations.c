/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-shapes-calculations.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:37 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/20 17:02 by hmontoya         ###   ########.fr     	  */
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

static void	set_sphere_data(t_sph_hit *hit, t_sphere *s, const t_ray *ray)
{
	hit->oc = sub_v3(s->pos, ray->origin);
	hit->a = length_v3(ray->direction) * length_v3(ray->direction);
	hit->h = dot(&ray->direction, &hit->oc);
	hit->c = length_v3(hit->oc) * length_v3(hit->oc) - s->rad * s->rad;
	hit->discriminant = hit->h * hit->h - hit->a * hit->c;
	hit->sqrtd = sqrt(hit->discriminant);
	hit->root = (hit->h - hit->sqrtd) / hit->a;
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

	s = (t_sphere *)shp;
	set_sphere_data(&hit, s, ray);
	if (hit.discriminant < 1e-6)
		return (0);
	if (!interval_surrounds(ray_limits, hit.root))
	{
		hit.root = (hit.h + hit.sqrtd) / hit.a;
		if (!interval_surrounds(ray_limits, hit.root))
			return (0);
	}
	rec->t = hit.root;
	rec->shape_pos = s->pos;
	rec->rgb = s->rgb;
	rec->type = 3;
	rec->hit = at((t_ray *)ray, rec->t);
	rec->normal = div_v3_dbl(sub_v3(rec->hit, s->pos), s->rad);
	set_face_normal(ray, &rec->normal, rec);
	return (1);
}

bool	hit(const t_ray *r, t_interval *lim, t_hit_data *rec)
{
	t_scene		*n;
	t_lst		*s;
	t_hit_data	h;
	double		closest;
	bool		hit_anything;

	hit_anything = false;
	n = get_scene();
	s = n->shapes;
	closest = lim->max;
	while (s)
	{
		init_limits(lim, lim->min, closest);
		if (n->check_hit[s->type - 3]((void *)s->cnt, r, (t_interval *)lim, &h))
		{
			hit_anything = true;
			if (closest > h.t)
			{
				closest = h.t;
				*rec = h;
			}
		}
		s = s->next;
	}
	return (hit_anything);
}
