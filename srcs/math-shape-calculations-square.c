/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-shape-calculations-square.c                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:54:39 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/06 12:54:41 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"
#include "shape-maths.h"
#include "vectors.h"
#include "ray.h"
#include "lights.h"

static void init_hit_data(t_square_hit	*hit, t_square *sq)
{
	hit->denom = 0;
	hit->half_size_x = sq->size.x * 0.5;
	hit->half_size_y = sq->size.y * 0.5;
	hit->hit_point = vec3(0, 0, 0);
	hit->i = vec3(0, 1, 0);
	hit->j = vec3(1, 0, 0);
	if (fabs(sq->axis.x) > 0.9)
        hit->u = normalize_v3(cross(&sq->axis, &hit->i));
    else
        hit->u = normalize_v3(cross(&sq->axis, &hit->j));
    hit->v = normalize_v3(cross(&sq->axis, &hit->u));
	hit->local_hit = vec3(0, 0, 0);
	hit->oc = vec3(0, 0, 0);
	hit->u_proj = 0;
	hit->v_proj = 0;
}


static int intersect_square(t_square *sq, const t_ray *ray, t_interval *ray_limits, t_hit_data *rec)
{
	t_square_hit	hit;
	double			t;
    
	init_hit_data(&hit, sq);
	hit.denom = dot(&sq->axis, &ray->direction);
	if (fabs(hit.denom) < 1e-6)
		return (0);
	hit.oc = sub_v3(sq->pos, ray->origin);
	t = dot(&hit.oc, &sq->axis) / hit.denom;
	if (!interval_surrounds(ray_limits, t))
		return (0);
	hit.hit_point = sum_v3(ray->origin, scale_v3(ray->direction, t));
	hit.local_hit = sub_v3(hit.hit_point, sq->pos);
	hit.u_proj = dot(&hit.local_hit, &hit.u);
	hit.v_proj = dot(&hit.local_hit, &hit.v);
	if (fabs(hit.u_proj) > hit.half_size_x || fabs(hit.v_proj) > hit.half_size_y)
		return (0);
	rec->t = t;
	rec->hit = at((t_ray *)ray, rec->t);
	set_face_normal(ray, &sq->axis, rec);
	return (1);
}

/**
 * @brief
 * square equation a(x−x0​)+b(y−y0​)+c(z−z0​)=0 
 * t=−(n⋅(O−P0​)/m​⋅d)
 * n = normal
 * d = ray direction
 */
int	hit_square(void *shp, const t_ray *ray, t_interval *ray_limits,
	t_hit_data *rec)
{
	t_square	*sq;
    t_hit_data  temp;
    int         hit_any;

	sq = (t_square *)shp;
	rec->rgb = sq->rgb;
	rec->orgb = sq->rgb;
    hit_any = 0;
    temp = *rec;
    if (intersect_square(sq, ray, ray_limits, &temp))
    {
        hit_any = 1;
        *rec = temp;
        ray_limits->max = temp.t;
    }
	return (hit_any);
}