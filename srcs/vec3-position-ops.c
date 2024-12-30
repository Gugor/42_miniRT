/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-position-ops.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:26 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/30 16:54:49 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "maths.h"

float	dot(const t_vec3 *v1, const t_vec3 *v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vec3	cross(const t_vec3 *v1, const t_vec3 *v2)
{
	t_vec3	new;

	new.x = (v1->y * v2->z - v1->z * v2->y);
	new.y = (v1->z * v2->x - v1->x * v2->z);
	new.z = (v1->x * v2->y - v1->y * v2->x);
	return (new);
}
