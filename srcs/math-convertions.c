/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/31 19:55:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "maths.h"
#include "vectors.h"

double degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}
static double   sqr_color(t_color color)
{
	return (color.r * color.r + color.g * color.g + color.b * color.b);
}

static int  color_intensity(t_color color)
{
    return ((int)sqrt((int)sqr_color(color)));
}

bool    is_brighter(t_color color1, t_color color2)
{
    if (color_intensity(color1) > color_intensity(color2))
        return (1);
    return (0);
}