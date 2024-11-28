/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 17:00:50 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "vectors.h"

/**
 * @brief It converst from vec3 to t_color
*/
t_color	vec3_to_rgb(t_vec3 *v3)
{
	t_color	rgb;

	rgb.r = v3->x;
	rgb.g = v3->y;
	rgb.b = v3->z;
	return (rgb);
}
