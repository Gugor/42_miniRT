/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-float-operations.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:38 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/12 23:38:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"

t_vec3	scale_v3(t_vec3 v1, double t)
{
	t_vec3	new;

	new.x = v1.x * t;
	new.y = v1.y * t;
	new.z = v1.z * t;
	return (new);
}

t_vec3	div_v3_dbl(t_vec3 v1, double t)
{
	t_vec3	new;

	new.x = v1.x / t;
	new.y = v1.y / t;
	new.z = v1.z / t;
	return (new);
}

t_vec3	sum_v3_dbl(t_vec3 v1, double t)
{
	t_vec3	new;

	new.x = v1.x + t;
	new.y = v1.y + t;
	new.z = v1.z + t;
	return (new);
}

t_vec3	sub_v3_dbl(t_vec3 v1, double t)
{
	t_vec3	new;

	new.x = v1.x - t;
	new.y = v1.y - t;
	new.z = v1.z - t;
	return (new);
}

double	vec3_to_dbl(t_vec3 v)
{
	return (v.x + v.y + v.z);
}
