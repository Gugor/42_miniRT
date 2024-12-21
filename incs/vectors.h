/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:19:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/21 14:57:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the math of the project, vectors and shapes creation.
*/
#ifndef VECTORS_H
# define VECTORS_H

# include <stdint.h>
# include <math.h>
# include <stdio.h>
# include "colours.h"

typedef enum e_vec_type
{
	VEC2,
	VEC3
}	t_vec_type;

typedef struct s_vec2
{
	float	x;
	float	y;
}	t_vec2;

typedef struct s_ivec2
{
	int	x;
	int	y;
}	t_ivec2;


typedef struct s_vec3
{
	float	x;
	float	y;
	float	z;
}	t_vec3;

typedef t_vec3	t_p3;
typedef t_vec3	t_p2;

/*							Math in Range									  */
int			in_range_dbl(float val, float min, float max);
int			in_range_vec3(t_vec3 val, float min, float max);


/*							Math Convertions								  */

/*							Vec3 Operations 1								  */
// void		vec3(t_vec3 *v3, float x, float y, float z);
t_vec3		vec3(float x, float y, float z);
t_vec3		mult_v3(t_vec3 v1, t_vec3 v2);
t_vec3		div_v3(t_vec3 v1, t_vec3 v2);
t_vec3		sum_v3(t_vec3 v1, t_vec3 v2);
t_vec3		sub_v3(t_vec3 v1, t_vec3 v2);
/*							Vec3 Operations 2								  */
float		sqr_v3(t_vec3 v3);
float		length_v3(t_vec3 v3);
t_vec3		normalize_v3(t_vec3 v3);
/*							Vec3 Operation float							  */
t_vec3		scale_v3(t_vec3 v1, float t);
t_vec3		div_v3_dbl(t_vec3 v1, float t);
t_vec3		sum_v3_dbl(t_vec3 v1, float t);
t_vec3		sub_v3_dbl(t_vec3 v1, float t);
float		vec3_to_dbl(t_vec3 v3);
/*							Vec3 Operation float							  */
float		dot(const t_vec3 *v1, const t_vec3 *v2);
t_vec3		cross(const t_vec3 *v1, const t_vec3 *v2);

#endif
