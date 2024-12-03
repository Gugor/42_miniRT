/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/03 14:48:54 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include "vectors.h"

typedef union s_ucolor
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;	
	int		clr;
	
}	t_ucolor;

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

typedef struct s_vec3 t_vec3;

t_color		set_color(uint8_t r, uint8_t g, uint8_t b);
t_color		vec3_to_rgb(t_vec3 *v3);
int			in_range_rgb(t_color val, uint8_t min, uint8_t max);
double 		lerpRGB(double unscaled, double min_limit,
			double 	max_limit, double min, double max);
t_ucolor	color_to_mlx(t_color *c);
			
#endif
