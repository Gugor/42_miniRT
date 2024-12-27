/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/21 10:54:01 hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "maths.h"

t_color	sum_rgb(t_color v1, t_color v2)
{
	t_color		new;
	int			r;
	int			g;
	int			b;
	t_interval	inter;

	inter.min = 0;
	inter.max = 255.9999;
	r = 0;
	g = 0;
	b = 0;
	r = (int)clamp(&inter, ((get_r(v1) + get_r(v2)) * 0.5));
	g = (int)clamp(&inter, ((get_g(v1) + get_g(v2)) * 0.5));
	b = (int)clamp(&inter, ((get_b(v1) + get_b(v2)) * 0.5));
	new.clr = r << 16 | g << 8 | b;
	return (new);
}
/**
 * @brief This funtion scale a rgb color in the uint8 range [0, 255].
 */
t_color scale_color(t_color rgb, float scale)
{
	t_color new;
	int r;
	int g;
	int b;
	t_interval inter;
	t_interval inter2;

	inter.min = 0;
	inter.max = 1;
	inter2.min = 0;
	inter2.max = 255;
	scale = clamp(&inter, scale);
	r = (int)clamp(&inter2, get_r(rgb) * scale);
	g = (int)clamp(&inter2, get_g(rgb) * scale);
	b = (int)clamp(&inter2, get_b(rgb) * scale);
	new.clr = r << 16 | g << 8 | b;
	return (new);
}

/**
 * @brief This function scales a color with the given params.
 * RGB chanels are scalars numbers between 0 and 1. You need to see
 * this values as the percentage this channel is going to be activated.
 * 0 is 0 and 1.0 is 255.
 */
t_color	scale_rgb(float r, float g, float b)
{
	t_color		c;
	t_interval	inter;

	inter.min = 0;
	inter.max = 0.9999;

	c.clr = ((uint8_t)(255.999 * clamp(&inter, r)) << 16
			| (uint8_t)(255.999 * clamp(&inter, g)) << 8
			| (uint8_t)(255.999 * clamp(&inter, b)));
	return (c);
}

t_color	color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	c;

	c.clr = (uint8_t)(r) << 16 | (uint8_t)(g) << 8 | (uint8_t)(b);
	return (c);
}

t_color	clamp_color(t_color c)
{
	float		r;
	float		g;
	float		b;
	t_interval	inter;
	t_color		new;

	inter.min = 0;
	inter.max = 255.9999;
	r = clamp(&inter, get_r(c));
	g = clamp(&inter, get_g(c));
	b = clamp(&inter, get_b(c));
	new.clr = ((int)r << 16) | ((int)g << 8) | (int)(b);
	return (new);
}
