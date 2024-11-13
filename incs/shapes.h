/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:14:49 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/13 18:25:22 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHAPES_H
#define SHAPES_H

#include "mrt_math.h"

typedef struct s_plane
{
	t_vec3 p1;		
	t_vec3 p2;		
	t_color rgb;
}	t_plane;

#endif

