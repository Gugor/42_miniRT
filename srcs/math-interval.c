/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-interval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/23 18:46:09 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"

void init_limits(t_interval *inter, float min, float max)
{
	inter->min = min;
	inter->max = max;	
}

bool interval_contains(t_interval *inter, float p)
{
	return (inter->min <= p && inter->max >= p);
}
bool interval_sourrounds(t_interval *inter, float p)
{
	return (inter->min < p && p < inter->max);
}

float interval_size(t_interval *inter)
{
	return (inter->max - inter->min);
}
