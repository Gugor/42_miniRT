/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-shapes-normals.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:59 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:25:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "shapes.h"
#include "shape-maths.h"

// Sets the hit record normal vector.
// NOTE: the parameter `outward_normal` is assumed to have unit length.
void	set_face_normal(const t_ray *r, const t_vec3 *outward_normal,
		t_hit_data *hitd)
{
	hitd->is_front = dot(&r->direction, outward_normal) <= -1e-160;
	if (hitd->is_front)
		hitd->normal = *outward_normal;
	else
		hitd->normal = scale_v3(*outward_normal, -1);
}
