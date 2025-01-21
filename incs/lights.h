/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:33 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of lights
*/
#ifndef LIGHTS_H
# define LIGHTS_H

# include "vectors.h"
# include "colours.h"

typedef struct s_ambient
{
	double	intensity;
	t_color	rgb;
}	t_ambient;

typedef struct	s_light
{
	double	brghtnss;
	t_vec3	pos;
	t_color	rgb;
}	t_light;

typedef struct s_hit_data t_hit_data;

t_color			ambient_light_calc(t_color clr, t_ambient *alight);
void			calculate_lights(t_hit_data *hitd);
#endif
