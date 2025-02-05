/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/05 11:20:26 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include <stdbool.h>
# include "vectors.h"

typedef union s_color
{
	struct 
	{
		uint8_t	a;
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;	
	};
	int		clr;
}	t_color;

typedef struct s_ncolor
{
	struct
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	};
}	t_ncolor;

typedef struct s_vec3	t_vec3;

/*							Colours Utils								  */
t_color		vec3_to_rgb(t_vec3 v3);
int			in_range_rgb(t_color val, uint8_t min, uint8_t max);
int			lerpRGB(double pos, t_color from, t_color to);
t_color		clamp_intensity(t_color d);
/*							Math Colours								  */
t_color		sum_rgb(t_color c1, t_color c2);
t_color		scale_color(t_color rgb, double scale);
t_color		mean_rgb(t_color c1, t_color c2);
t_color		clamp_color(t_color c);
bool    is_brighter(t_color color1, t_color color2);

t_color		color(uint8_t r, uint8_t g, uint8_t b);

/*							Colours Getters		        				  */
uint8_t		get_r(t_color c);
uint8_t		get_g(t_color c);
uint8_t		get_b(t_color c);

#endif
