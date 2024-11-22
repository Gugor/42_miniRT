/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-in-range-utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:42:25 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/22 13:59:16 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "mrt-math.h"

/**
 * @brief It check if the given value is in range.
*/
int	in_range_dbl(double val, double min, double max)
{
	if (val < min || val > max)
		return (0);
	return (1);
}

/**
 * @brief It check if the given vec3 value are in range.
*/
int	in_range_vec3(t_vec3 val, double min, double max)
{
	if (val.x < min || val.x > max)
		return (0);
	if (val.y < min || val.y > max)
		return (0);
	if (val.z < min || val.z > max)
		return (0);
	return (1);
}

/**
 * @brief It check if the given vec3 value are in range.
*/
int	in_range_rgb(t_color val, uint8_t  min, uint8_t max)
{
	if (val.r < min || val.r > max)
		return (0);
	if (val.g < min || val.g > max)
		return (0);
	if (val.b < min || val.b > max)
		return (0);
	return (1);
}
