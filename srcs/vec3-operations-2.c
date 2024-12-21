/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec3-operations-2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:56 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/21 18:34:44 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include <math.h>

float sqr_v3(t_vec3 v3)
{
	return (v3.x * v3.x + v3.y * v3.y + v3.z * v3.z);
}

float length_v3(t_vec3 v3)
{
	return ((float)sqrt((double)sqr_v3(v3)));
}

t_vec3 normalize_v3(t_vec3 v3)
{
	if (length_v3(v3) == 0.0)
		return (vec3(0,0,0));
	return (div_v3_dbl(v3, length_v3(v3)));
}
