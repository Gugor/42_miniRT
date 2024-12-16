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
int get_SHP_pos(t_vec3 *pos, void *shp, t_entid type)
{
	if (type == PLANE)
	{
		t_plane *pl;
		pl = (t_plane *)shp;
		*pos = pl->pos;	
		return (0);
	}
	if (type == SPHERE)
	{
		t_sphere *sph;
		sph = (t_sphere *)shp;
		*pos = sph->pos;	
		return (0);
	}
	if (type == CYLINDER)
	{
		t_cylinder *cyl;
		cyl = (t_cylinder *)shp;
		*pos = cyl->pos;	
		return (0);
	}
	return (1);
}
