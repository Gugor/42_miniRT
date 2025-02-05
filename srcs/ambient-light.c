/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient-light.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 13:08:08 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/05 11:17:44 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "colours.h"
#include "lights.h"

/**
 * @brief It calculates the impact of the scene ambien light in a given color.
*/
t_color	ambient_light_calc(t_color clr, t_ambient *alight)
{
	// return (sum_rgb(clr, scale_color(sum_rgb(clr, alight->rgb), alight->intensity)));
	return (mean_rgb(clr, scale_color(alight->rgb, alight->intensity)));
}