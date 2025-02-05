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

/**
 * @brief It calculates the gamma correction for the given pixel
*/
t_color gamma_correction(t_color clr, double gamma)
{
	t_interval	inter;
	t_color		new;

	inter.min = 0;
	inter.max = 255;
	new.clr |= (int)clamp(&inter, pow(get_r(clr), 1.0f / gamma)) << 16;
	new.clr |= (int)clamp(&inter, pow(get_g(clr), 1.0f / gamma)) << 8;
	new.clr |= (int)clamp(&inter, pow(get_b(clr), 1.0f / gamma));
	return (new);
}


/**
 * Maps the a dimention into another by scaling it.
 *  
*/
int lerpRGB(double pos, t_color from, t_color to)
{
	double		a;
	t_ncolor	f;
	t_ncolor	t;
	t_color 	i;

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
	return(i.clr);
}

t_color clamp_intensity(t_color d)
{
	t_interval inter;
	t_color new; 
	int r;
	int g;
	int b;

	inter.min = 0.0;
	inter.max = 0.999;
	r = (int)(256 * clamp(&inter, ((d.clr >> 16) & 0xFF)) / 255.9999);
	g =	(int)(256 * clamp(&inter, ((d.clr >> 8) & 0xFF) / 255.9999));
	b = (int)(256 * clamp(&inter, (d.clr & 0xFF) / 255.999));
	new.clr = r << 16 | g << 8 | b;
	return (new);
}
