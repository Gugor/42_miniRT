/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-rand-generation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:10 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/22 13:06:56 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths.h"
#include "vectors.h"

double	random_double_range(double min, double max)
{
	return (min + (max - min) * random_double());
}

t_vec3	random_v3(void)
{
	return (vec3(random_double(), random_double(), random_double()));
}

t_vec3	random_range_v3(double min, double max)
{
	return (vec3(random_double_range(min, max), random_double_range(min, max),
			random_double_range(min, max)));
}

t_vec3	random_unit_vector(void)
{
	t_vec3	p;
	double	lensq;

	while (true)
	{
		p = random_range_v3(-1, 1);
		lensq = length_v3(p) * length_v3(p);
		if (1e-160 < lensq && lensq <= 1.0f)
			return (div_v3_dbl(p, sqrt(lensq)));
	}
}

t_vec3	random_on_hemisphere(const t_vec3 normal)
{
	t_vec3	on_unit_sphere;

	on_unit_sphere = random_unit_vector();
	if (dot(&on_unit_sphere, &normal) > 1e-6)
		return (on_unit_sphere);
	else
		return (scale_v3(on_unit_sphere, -1));
}
