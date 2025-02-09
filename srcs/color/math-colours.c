/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 13:02:08 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/07 13:02:10 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"
#include "maths.h"

t_color	sum_rgb(t_color c1, t_color c2)
{
	t_color		new;
	int			r;
	int			g;
	int			b;
	t_interval	inter;

	inter.min = 0;
	inter.max = 255;
	r = 0;
	g = 0;
	b = 0;
	r = (int)clamp(&inter, get_r(c1) + get_r(c2));
	g = (int)clamp(&inter, get_g(c1) + get_g(c2));
	b = (int)clamp(&inter, get_b(c1) + get_b(c2));
	new.clr = r << 16 | g << 8 | b;
	return (new);
}

/**
 * @brief This funtion scale a rgb color in the uint8 range [0, 255].
 */
t_color	scale_color(t_color rgb, double scale)
{
	t_color		new;
	int			r;
	int			g;
	int			b;
	t_interval	inter;

	inter.min = 0;
	inter.max = 255;
	scale = clamp(&inter, scale);
	r = (int)clamp(&inter, get_r(rgb) * scale);
	g = (int)clamp(&inter, get_g(rgb) * scale);
	b = (int)clamp(&inter, get_b(rgb) * scale);
	new.clr = r << 16 | g << 8 | b;
	return (new);
}

/**
 * @brief This function scales a color with the given params.
 * RGB chanels are scalars numbers between 0 and 1. You need to see
 * this values as the percentage this channel is going to be activated.
 * 0 is 0 and 1.0 is 255.
 */
t_color	mean_rgb(t_color c1, t_color c2)
{
	t_color		new;
	int			r;
	int			g;
	int			b;

	r = 0;
	g = 0;
	b = 0;
	r = (int)(get_r(c1) + get_r(c2)) *0.5;
	g = (int)(get_g(c1) + get_g(c2)) *0.5;
	b = (int)(get_b(c1) + get_b(c2)) *0.5;
	new.clr = r << 16 | g << 8 | b;
	return (new);
}

t_color	color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color	c;

	c.clr = (uint8_t)(r) << 16 | (uint8_t)(g) << 8 | (uint8_t)(b);
	return (c);
}

t_color	clamp_color(t_color c)
{
	double		r;
	double		g;
	double		b;
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
