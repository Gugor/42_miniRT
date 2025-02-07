/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights-utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 14:43:54 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/07 14:44:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "lights.h"

/**
 * @brief It initialize a t_highlight struct with the ambient light, and 
 * set diffuse color and specular to default.
*/
void	init_highlights(t_highlight *hl, t_color *albedo)
{
	hl->ambient_clr = ambient_light_calc(*albedo, &get_scene()->alight);
	hl->diffusse_clr = color(0, 0, 0);
	hl->specular_clr = color(0, 0, 0);
	hl->rgb = hl->ambient_clr;
}

/**
 * @brief It updates the t_higlights struct with the data of the new light.
*/
void	update_higlights(t_highlight *hl, t_light *light, t_hit_data *hitd)
{
	hl->brightness = light->brghtnss;
	hl->origin = light->pos;
	hl->dir = sub_v3(hl->origin, hitd->hit);
	hl->dir_norm = normalize_v3(hl->dir);
}
