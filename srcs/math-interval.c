/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-interval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:47:54 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"

void init_limits(t_interval *inter, double min, double max)
{
	inter->min = min;
	inter->max = max;	
}

bool interval_contains(t_interval *inter, double p)
{
	return (inter->min <= p && inter->max >= p);
}
bool interval_sourrounds(t_interval *inter, double p)
{
	return (inter->min < p && inter->max > p);
}

double interval_size(t_interval *inter)
{
	return (inter->max - inter->min);
}
