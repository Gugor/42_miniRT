/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-in-range-utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:25 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/17 11:39:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vectors.h"

/**
 * @brief It check if the given value is in range.
*/
int	in_range_dbl(float val, float min, float max)
{
	if (val < min || val > max)
		return (0);
	return (1);
}

/**
 * @brief It check if the given vec3 value are in range.
*/
int	in_range_vec3(t_vec3 val, float min, float max)
{
	if (val.x < min || val.x > max)
		return (0);
	if (val.y < min || val.y > max)
		return (0);
	if (val.z < min || val.z > max)
		return (0);
	return (1);
}



