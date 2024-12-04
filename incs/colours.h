/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/04 14:15:08 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include "vectors.h"

typedef union s_color
{
	uint8_t	a;
	uint8_t	r;
	uint8_t	g;
	uint8_t	b;	
	int		clr;
	
}	t_color;

typedef struct s_ncolor
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int);
}	t_ncolor;

typedef struct s_acolor
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int, unsigned int);
}	t_acolor;

typedef struct s_vec3 t_vec3;

/*							Colours Utils								  */
t_color		set_color(uint8_t r, uint8_t g, uint8_t b);
t_color		vec3_to_rgb(t_vec3 *v3);
int			in_range_rgb(t_color val, uint8_t min, uint8_t max);
t_color		scale_rgb(double r, double g, double b);
int			lerpRGB(double pos, t_color from, t_color to);
/*							Math Colours								  */
t_color		sum_rgb(t_color *v1, t_color *v2);
			
#endif
