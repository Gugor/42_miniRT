/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mrt-math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:19:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 11:01:07 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the math of the project, vectors and shapes creation.
*/
#ifndef MRT_MATH_H
# define MRT_MATH_H

# include <stdint.h>
# include "colours.h"
#include <stdio.h>

typedef enum e_vec_type
{
	VEC2,
	VEC3
}	t_vec_type;

typedef struct s_vec2
{
	double	x;
	double	y;
}	t_vec2;

typedef struct s_vec3
{
	double	x;
	double	y;
	double	z;
}	t_vec3;

typedef t_vec3	t_p3;
typedef t_vec3	t_p2;

t_color		vec3_to_rgb(t_vec3 *v3);
int			in_range_dbl(double val, double min, double max);
int			in_range_vec3(t_vec3 val, double min, double max);
int			in_range_rgb(t_color val, uint8_t min, uint8_t max);
#endif
