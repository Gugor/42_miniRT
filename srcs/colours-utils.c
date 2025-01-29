/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:13 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"
#include "colours.h"

/**
 * @brief It check if the given vec3 value are in range.
*/
int	in_range_rgb(t_color val, uint8_t min, uint8_t max)
{
	if (val.r < min || val.r > max)
		return (0);
	if (val.g < min || val.g > max)
		return (0);
	if (val.b < min || val.b > max)
		return (0);
	return (1);
}

/**
 * @brief It converst from vec3 to t_color
*/
t_color	vec3_to_rgb(t_vec3 v3)
{
	t_color	rgb;

	rgb.clr = ((uint8_t)v3.x << 16) | ((uint8_t)v3.y << 8) | (uint8_t)v3.z;
	return (rgb);
}

/**
 * Maps the a dimention into another by scaling it.
 *  
*/
int	lerprgb(double pos, t_color from, t_color to)
{
	double		a;
	t_ncolor	f;
	t_ncolor	t;
	t_color		i;

	i.clr = 0;
	f.r = (from.clr >> 16) & 0xFF;
	f.g = (from.clr >> 8) & 0xFF;
	f.b = (from.clr) & 0xFF;
	t.r = (to.clr >> 16) & 0xFF;
	t.g = (to.clr >> 8) & 0xFF;
	t.b = (to.clr) & 0xFF;
	a = 0.5 * pos + 1.0;
	i.clr |= (uint8_t)((1.0 - a) * f.r + a * t.r) << 16;
	i.clr |= (uint8_t)((1.0 - a) * f.g + a * t.g) << 8;
	i.clr |= (uint8_t)((1.0 - a) * f.b + a * t.b);
	return (i.clr);
}

t_color	clamp_intensity(t_color d)
{
	t_interval	inter;
	t_color		new;
	int			r;
	int			g;
	int			b;

	inter.min = 0.0;
	inter.max = 0.999;
	r = (int)(256 * clamp(&inter, ((d.clr >> 16) & 0xFF)) / 255.9999);
	g = (int)(256 * clamp(&inter, ((d.clr >> 8) & 0xFF) / 255.9999));
	b = (int)(256 * clamp(&inter, (d.clr & 0xFF) / 255.999));
	new.clr = r << 16 | g << 8 | b;
	return (new);
}
