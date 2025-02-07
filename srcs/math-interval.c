/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-interval.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:48 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"

void	init_limits(t_interval *inter, double min, double max)
{
	inter->min = min;
	inter->max = max;
}

bool	interval_contains(t_interval *inter, double p)
{
	return (inter->min <= p && inter->max >= p);
}
// bool interval_surrounds(t_interval *inter, double p)
// {
// 	return (inter->min < p && p < inter->max);
// }

bool	interval_surrounds(t_interval *inter, double p)
{
	double	epsilon;

	epsilon = 1e-6;
	return ((inter->min - epsilon) < p && p < (inter->max + epsilon));
}

double	interval_size(t_interval *inter)
{
	return (inter->max - inter->min);
}
