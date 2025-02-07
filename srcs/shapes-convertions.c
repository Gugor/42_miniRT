/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes-convertions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:51:11 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:51:14 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shapes.h"

/**
 * @brief It gets the position value in a given shapes and stores it
 * in the `pos` argument.
 */
int	get_shp_pos(t_vec3 *pos, void *shp, t_entid type)
{
	t_cylinder	*cyl;
	t_plane		*pl;
	t_sphere	*sph;

	if (type == PLANE)
	{
		pl = (t_plane *)shp;
		*pos = pl->pos;
		return (0);
	}
	if (type == SPHERE)
	{
		sph = (t_sphere *)shp;
		*pos = sph->pos;
		return (0);
	}
	if (type == CYLINDER)
	{
		cyl = (t_cylinder *)shp;
		*pos = cyl->pos;
		return (0);
	}
	return (1);
}
