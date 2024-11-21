/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:14:49 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 14:18:19 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of shapes
*/
#ifndef SHAPES_H
# define SHAPES_H

# include "mrt-math.h"
# include "materials.h"
# include "scene.h"

typedef struct s_plane
{
	t_vec3		pos;		
	t_vec2		axis;		
	t_color		rgb;
	t_material	material;
}	t_plane;

typedef struct s_sphere
{
	t_vec3		pos;		
	double		size;
	t_color		rgb;
	t_material	material;
}	t_sphere;

typedef struct s_cylinder
{
	int			indx;
	t_vec3		pos;		
	t_vec3		axis;		
	t_vec2		size;
	t_color		rgb;
	t_material	material;
}	t_cylinder;

#endif

