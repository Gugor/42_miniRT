/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:33 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 17:01:31 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of lights
*/
#ifndef LIGHTS_H
# define LIGHTS_H

# include "scene.h"
# include "vectors.h"
# include "colours.h"

typedef struct s_ambient
{
	double	range;
	t_color	rgb;
}	t_ambient;

typedef struct	s_light
{
	double	brghtnss;
	t_vec3	pos;
	t_color	rgb;
}	t_light;

#endif
