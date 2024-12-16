/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours-utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:13 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:45:16 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"
#include "colours.h"

/**
 * @brief
 */
t_color set_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
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
	// printf("		:: [%f]From RGB[%u,%u,%u]\n",pos, f.r, f.g , f.b);
	t.r = (to.clr >> 16) & 0xFF; 
	t.g = (to.clr >> 8) & 0xFF; 
	t.b = (to.clr) & 0xFF; 
	// printf("		:: [%f]To RGB[%u,%u,%u]\n",pos, t.r, t.g , t.b);
	a = 0.5 * pos + 1.0; 
	// printf("			-> I[%f]\n", a);
	i.clr |= (uint8_t)((1.0 - a) * f.r + a * t.r) << 16;
	// printf("			-> R[%d][%u]\n", (i.clr >> 16) & 0xFF, (uint8_t)((1.0 - a) * f.r + a * t.r));
	i.clr |= (uint8_t)((1.0 - a) * f.g + a * t.g) << 8;
	// printf("			-> G[%d][%u]\n", (i.clr >> 8) & 0xFF, (uint8_t)((1.0 - a) * f.g + a * t.g));
	i.clr |= (uint8_t)((1.0 - a) * f.b + a * t.b);
	// printf("			-> B[%d][%u]\n", i.clr & 0xFF, (uint8_t)((1.0 - a) * f.b + a * t.b));
	// printf("		::->[%f]Interpolated RGB[%u,%u,%u][%i]\n",a, (i.clr >> 16) & 0xFF, (i.clr >> 8) & 0xFF , i.clr & 0xFF, i.clr);
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
	r = (int)(256 * clamp(&inter, (d.clr >> 16) & 0xFF));
	g =	(int)(256 * clamp(&inter, (d.clr >> 8) & 0xFF));
	b = (int)(256 * clamp(&inter, d.clr & 0xFF));
	new.clr = r << 16 | g << 8 | b;
	return (new);
}
