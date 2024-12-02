/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/02 22:26:00 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include "vectors.h"

typedef struct s_color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int);
}	t_color;

typedef struct s_acolor
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int, unsigned int);
}	t_acolor;

int			in_range_rgb(t_color val, uint8_t min, uint8_t max);
double 		lerpRGB(double unscaled, double min_limit,
			double max_limit, double min, double max);
#endif
