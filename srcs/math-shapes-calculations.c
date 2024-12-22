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
	denominator = dot(&pl->axis, &ray->norm);
	if (fabs(denominator) < 1e-6)
		return (0);
	hitd.oc = sub_v3(ray->origin, pl->pos);
	t = dot(&pl->axis, &hitd.oc) / denominator;
	if (!interval_sourrounds(ray_limits, t))
		return (0);
	// printf("Plane hit\n");
	rec->t = t;
	rec->rgb = pl->rgb;
	rec->hit = sum_v3(ray->origin, scale_v3(ray->direction, rec->t));
	rec->out_normal = pl->axis;
	set_face_normal(ray, &rec->out_normal, rec);
	return (1);
}


/**
 * @brief It verifiys if a given ray intersects with the given sphere
 *
 *  `a = Representa el coeficiente cuadrático de la ecuación cuadrática que describe la intersección del rayo con la esfera.
 *	Matemáticamente, es igual a la magnitud al cuadrado del vector de dirección del rayo.`
 *	`h = Es el término lineal de la ecuación cuadrática.
 *	Representa el producto escalar entre la dirección del rayo (dd) y el vector que va desde el origen del rayo (oo) al centro de la esfera (ococ):
 *	h=d⋅oc.`
 *	`c = `
 *	`discriminant = `
 */
float tst_hit_sphere (const t_p3 *center, float r, const t_ray *ray)
{
	t_vec3 oc;
	float a;
	float b;
	float c;
	float discriminant;

	// printf("Sphere c[%f,%f,%f] => Ray or[%f,%f,%f] - dir[%f,%f,%f]\n",
	// 		center->x, center->y, center->z,
	// 		ray->origin.x, ray->origin.y, ray->origin.z,
	// 		ray->direction.x, ray->direction.y, ray->direction.z);
	oc = sub_v3(*center, ray->origin);	
	// printf ("oc[%f,%f,%f] ", oc.x, oc.y, oc.z);
	a = dot(&ray->direction, &ray->direction);
	// printf("a = \"%f\" ", a);
	b = -2.0 * dot(&ray->direction, &oc);
	// printf("b = \"%f\" ", b);
	c = dot(&oc, &oc) - r * r;
	// printf("c = \"%f\" ", b);
	discriminant = b * b - 4 * a * c;
	// printf("discriminant = \"%f\"\n", discriminant);
	// return (discriminant >= 0);
	if (discriminant < 0)
		return -1.0;
	else
		return ((-b - sqrt(discriminant)) / (2.0 * a));
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
 *	It has 3 different states: < 0 no hit, 0 one hit(tangent), > 0 2-hits (travese the sphere). 	 
*/
int hit_sphere (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{
	t_sph_hit hit;
	t_sphere *s;
	float sqrtd;
	float root;
	s = (t_sphere *)shp;
	hit.oc = sub_v3(s->pos, ray->origin);	
	hit.a =  length_v3(ray->direction) * length_v3(ray->direction);
	hit.h = dot(&ray->direction, &hit.oc);
	hit.c = length_v3(hit.oc) * length_v3(hit.oc) - s->rad * s->rad;

	hit.discriminant = hit.h * hit.h - hit.a * hit.c;
	if (hit.discriminant < 0)
		return (0);
	// printf("Drawing Sphere. Limits[%f,%f]\n", ray_limits->min, ray_limits->max);
	sqrtd = sqrt(hit.discriminant); 	
	root = (hit.h - sqrtd) / hit.a;
	// printf("Root limits[min:%f, max:%f] <> root:%f\n", ray_limits->min, ray_limits->max, root);
	if (!interval_sourrounds(ray_limits, root))// (root <= ray_limits->min || ray_limits->max <= root)
	{
		// printf("	:: Not root 1\n");
		root = (hit.h + sqrtd) / hit.a;
		if (!interval_sourrounds(ray_limits, root))//(root <= ray_limits->min || ray_limits->max <= root)
		{
			// printf("	:: Not root 2 => ");
			// printf(" Root limits[min:%f, max:%f] <> root:%f\n", ray_limits->min, ray_limits->max, root);
			return (0);
		}
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
int	hit_cylinder (void *shp, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{	
	t_cylinder	*cyl;
	t_cyl_hit	hitd;
	float		sqrtd;
	float		root1;
	float		root2;

	(void)ray_limits;

	cyl = (t_cylinder *)shp;
	hitd.oc = sum_v3(ray->origin, cyl->pos);
    hitd.d_proj = sum_v3(ray->direction, scale_v3(cyl->axis, dot(&ray->direction, &cyl->axis)));
    hitd.oc_proj = sum_v3(hitd.oc, scale_v3(cyl->axis, dot(&hitd.oc, &cyl->axis)));
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
			closest = hitd.t;
			// printf("====== Hit[%f] shape: %i\n", hitd.t, shapes->type);
			*rec = hitd;
			// printf("New lims [%f,%f] Det[%f] shape %i\n", lim->min, lim->max, hitd.t, shapes->type);
		}
		shapes = shapes->next;
	}
	return (hit_anything);
}
