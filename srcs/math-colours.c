/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-colours.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:00 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:47:02 by hmontoya         ###   ########.fr       */
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

	r = (int)((v1.r + v2.r) * 0.5);
	g = (int)((v1.g + v2.g) * 0.5);
	b = (int)((v1.b + v2.b) * 0.5);
	new.clr = r << 16 | g << 8 | b;
	// new = clamp_intensity(new);
	return (new);
}

t_color mult_rgb_dbl(t_color rgb, double scale)
{
	t_color new;
	int r;
	int g;
	int b;

	r = ((rgb.clr >> 16) & 0xFF) * scale;
	g = ((rgb.clr >> 8) & 0xFF) * scale;
	b = (rgb.clr & 0xFF) * scale;
	new.clr = r << 16	| g << 8 | b;
	return (new);
}

/**
 * @brief This function scales a color with the given params.
 * RGB chanels are scalars numbers between 0 and 1. You need to see
 * this values as the percentage this channel is going to be activated.
 * 0 is 0 and 1.0 is 255.
 */
t_color scale_rgb(double r, double g, double b)
{
	t_color c;

	c.clr = (uint8_t)(255.999 * r) << 16 | (uint8_t)(255.999 * g) << 8 | (uint8_t)(255.999 * b);
	return (c);
}
/*
t_color color_scale(t_color rgb, double scale)
{
	t_color	new;
	double	r;
	double	g;
	double	b;
	t_interval inter;

	inter.min = 0;
	inter.max = 255;
	r = clamp(inter,((rgb.clr >> 16) & 0xFF) * scale);
	g = clamp(inter,((rgb.clr >> 8) & 0xFF) * scale);
	b = clamp(inter,((rgb.clr) & 0xFF) * scale);
	new.clr = (uint8_t)r << 16 | (uint8_t)g << 8 | (uint8_t)b;
	return (new);
}*/

t_color color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color c;

	c.clr = (uint8_t)(r) << 16 | (uint8_t)(g) << 8 | (uint8_t)(b);
	return (c);
}

t_color clamp_color(uint32_t c)
{
	uint8_t		r;
	uint8_t		g;
	uint8_t		b;
	t_interval	inter;
	t_color		new;

	inter.min = 0;
	inter.max = 255;
	r = (uint8_t)clamp(&inter, ((c >> 16) & 0xFF));
	g = (uint8_t)clamp(&inter, ((c >> 8) & 0xFF));
	b = (uint8_t)clamp(&inter, (c) & 0xFF);
	new.clr = (r << 16) | (g << 8) | (b);
	return (new);
}
