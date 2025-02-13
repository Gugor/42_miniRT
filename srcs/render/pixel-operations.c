/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixel-operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 14:27:14 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/02/11 17:02:10 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vectors.h"
#include "maths.h"

/*
* @brief
* pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v)
*/
t_vec3	get_pix_rand_pos(t_vec3 *pix00, t_vec3 *dlt_u, t_vec3 *dlt_v,
		t_ivec2 *pix_pos)
{
	t_vec3	pu;
	t_vec3	pv;
	t_vec3	delta;

	pu = scale_v3(*dlt_u, (double)pix_pos->x);
	pv = scale_v3(*dlt_v, (double)pix_pos->y);
	delta = sum_v3(*pix00, pu);
	return (sum_v3(delta, pv));
}
