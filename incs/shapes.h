/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:14:49 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/09 18:55:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the creation and transformation of shapes
*/
#ifndef SHAPES_H
# define SHAPES_H

# include "vectors.h"
# include "ray.h"
# include "materials.h"
# include "scene.h"

typedef struct s_plane
{
	t_vec3		pos;		
	t_vec3		axis;		
	t_color		rgb;
	t_material	*material;
}	t_plane;

typedef struct s_sphere
{
	t_vec3		pos;		
	double		rad;
	t_color		rgb;
	t_material	*material;
}	t_sphere;

typedef struct s_cylinder
{
	int			indx;
	t_vec3		pos;		
	t_vec3		axis;		
	t_vec2		size;
	t_color		rgb;
	t_material	*material;
}	t_cylinder;

void set_face_normal(const t_ray *r, const t_vec3 *outward_normal, t_hit_data *rec);
int		get_SHP_pos(t_vec3 *pos, void *shp, t_entid type);
#endif

