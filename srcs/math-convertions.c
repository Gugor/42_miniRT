/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/10 12:50:56 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "maths.h"
#include "vectors.h"

void init_limits_def(t_interval *inter)
{
	inter->min = -INFINITY;
	inter->max = INFINITY;	
}

void init_limits(t_interval *inter, double min, double max)
{
	inter->min = min;
	inter->max = max;	
}

double degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}