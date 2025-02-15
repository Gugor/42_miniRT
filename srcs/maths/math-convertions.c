/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/02 18:56:28 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"
#include <stdlib.h>

double	degrees_to_radians(double degrees)
{
	return (degrees * PI / 180.0);
}

static double	sqr_color(t_color color)
{
	return (get_r(color) * get_r(color) + get_g(color)
		* get_g(color) + get_b(color) * get_b(color));
}

static float	color_intensity(t_color color)
{
	return ((float)sqrtf((float)sqr_color(color)));
}

bool	is_brighter(t_color color1, t_color color2)
{
	if (color_intensity(color1) > color_intensity(color2))
		return (1);
	return (0);
}

double	random_double(void)
{
	return (rand() / (RAND_MAX + 1.0));
}
