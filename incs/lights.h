/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:33 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 19:57:58 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of lights
*/
#ifndef LIGHTS_H
# define LIGHTS_H

# include "scene.h"
# include "mrt-math.h"
# include "colours.h"

typedef struct s_ambient
{
	t_color	rgb;
	double	range;
}	t_ambient;

typedef struct	s_light
{
	t_vec3	pos;
	t_color	rgb;
	double	brghtnss;
}	t_light;

#endif
