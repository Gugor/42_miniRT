/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-float-operations.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:38 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:51:47 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3		mult_v3_dbl(t_vec3 v1, float t)
{
	t_vec3 new;

	new.x = v1.x * t;
	new.y = v1.y * t;
	new.z = v1.z * t;
	return (new);
}

t_vec3	div_v3_dbl(t_vec3 v1, float t)
{
	t_vec3	new;

	// new.x = (1/t) * v1.x;
	// new.y = (1/t) * v1.y;
	// new.z = (1/t) * v1.z;
	new.x = v1.x / t;
	new.y = v1.y / t;
	new.z = v1.z / t;
	return (new);
}

t_vec3		sum_v3_dbl(t_vec3 v1, float t)
{
	t_vec3 new;
	new.x = v1.x + t;
	new.y = v1.y + t;
	new.z = v1.z + t;
	return (new);
}

t_vec3		rest_v3_dbl(t_vec3 v1, float t)
{
	t_vec3 new;
	new.x = v1.x - t;
	new.y = v1.y - t;
	new.z = v1.z - t;
	return (new);
}

float		vec3_to_dbl(t_vec3 v)
{
	return (v.x + v.y + v.z);
}
//return ((float)(v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
