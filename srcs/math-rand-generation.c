/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-rand-generation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:48:10 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/17 11:39:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "maths.h"
#include "vectors.h"

float random_float()
{
    return (rand() / (RAND_MAX + 1.0));
}

float random_range_db(float min, float max)
{
   float range = (max - min); 
   float div = RAND_MAX / range;
   return (min + (rand() / div));
    // return min + (max-min)*random_float();
}

t_vec3 random_v3()
{
    return (vec3(random_float(), random_float(), random_float()));
}

t_vec3 random_range_v3(float min, float max)
{
    return (vec3(random_range_db(min, max), random_range_db(min, max), random_range_db(min, max)));
}

t_vec3 random_unit_vector()
{
    while (true)
    {
        t_vec3 p = random_range_v3(-1,1);
        float lensq = length_v3(p) * length_v3(p);
         if (1e-160 < lensq && lensq <= 1)
            return div_v3_dbl(p, sqrt(lensq));
    }
}

t_vec3 random_on_hemisphere(const t_vec3 normal)
{
    t_vec3 on_unit_sphere = random_unit_vector();
    if (dot(&on_unit_sphere, &normal) > 0.0) // In the same hemisphere as the normal
        return (on_unit_sphere);
    else
        return (mult_v3_dbl(on_unit_sphere, -1));
}
