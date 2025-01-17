/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-interval-absolutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:34 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/16 18:24:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "maths.h"
#include "vectors.h"

void universe(t_interval *inter)
{
	inter->min = -INFINITY;
	inter->max = INFINITY;	
}

void empty(t_interval *inter)
{
	inter->min = INFINITY;
	inter->max = -INFINITY;	
}

double clamp(t_interval *inter, double x) 
{
	if (x < inter->min)
		return inter->min;
	if (x > inter->max)
		return inter->max;
	return x;
}
