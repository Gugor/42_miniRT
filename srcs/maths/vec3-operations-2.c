/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-operations-2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:56 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:38:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "error-handler.h"
#include <math.h>

double	sqr_v3(t_vec3 v3)
{
	return (v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
}

double	length_v3(t_vec3 v3)
{
	return ((double)sqrt((double)sqr_v3(v3)));
}

static double	inv_sqrt_v3(t_vec3 v3)
{
	double	sq;

	sq = sqr_v3(v3);
	if (sq == 0.0f)
		return (0.0f);
	return (1.0f / sqrtf(sq));
}

t_vec3	normalize_v3(t_vec3 v3)
{
	double	inv_len;

	inv_len = inv_sqrt_v3(v3);
	if (inv_len == 0.0f)
		return ((t_vec3){0, 0, 0});
	return ((t_vec3){v3.x * inv_len, v3.y * inv_len, v3.z * inv_len});
}
