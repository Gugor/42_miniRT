/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:14:49 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 17:17:02 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of shapes
*/
#ifndef SHAPES_H
#define SHAPES_H

#include "mrt-math.h"
#include "colours.h"
#include "materials.h"

typedef struct s_plane
{
	double (*geometry)();		
	t_vec3 pos;		
	t_vec2 axis;		
	t_color rgb;
	t_material material;
}	t_plane;

typedef struct s_sphere
{
	double (*geometry)();		
	t_vec3 pos;		
	double size;
	t_color rgb;
	t_material material;
}	t_sphere;

typedef struct s_cylinder
{
	double (*geometry)();		
	t_vec3 pos;		
	t_vec3 axis;		
	t_vec2 size;
	t_color rgb;
	t_material material;
}	t_cylinder;

#endif

