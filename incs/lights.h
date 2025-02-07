/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:26:33 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/07 16:29:26 by hmontoya         ###   ########.fr       */
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

typedef struct s_light
{
	double	brghtnss;
	t_vec3	pos;
	t_color	rgb;
}	t_light;

typedef struct s_higlight
{
	t_vec3	origin;	
	t_color	ambient_clr;
	t_color	diffusse_clr;
	t_color	specular_clr;
	double	attenuation;
	double	intensity;
	double	diffuse;
	double	specular;
	double	dist_to_light;
	double	brightness;
	t_vec3	dir;
	t_vec3	dir_norm;
	t_vec3	view_dir;
	t_vec3	half_dir;
	t_color	rgb;
}	t_highlight;


typedef struct s_hit_data	t_hit_data;

t_color			ambient_light_calc(t_color clr, t_ambient *alight);
void			calculate_lights(t_hit_data *hitd);

void			init_highlights(t_highlight *hl, t_color *albedo);
void			update_higlights(t_highlight *hl, t_light *light,
					t_hit_data *hitd);
#endif
