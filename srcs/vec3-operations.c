/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:52:12 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	vec3(double x, double y, double z)
{
	t_vec3	v3;

	v3.x = x;
	v3.y = y;
	v3.z = z;
	return (v3);
}

t_vec3	sum_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	new;

	new.x = v1.x + v2.x;
	new.y = v1.y + v2.y;
	new.z = v1.z + v2.z;
	return (new);
}

t_vec3	sub_v3(t_vec3 v1, t_vec3 v2)
{
	t_vec3	new;

	new.x = v1.x - v2.x;
	new.y = v1.y - v2.y;
	new.z = v1.z - v2.z;
	return (new);
}
//return ((double)(v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
