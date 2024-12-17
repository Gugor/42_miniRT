/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-interval-absolutes.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:47:34 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/17 11:39:45 by hmontoya         ###   ########.fr       */
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

float clamp(t_interval *inter, float x) 
{
	if (x < inter->min)
		return inter->min;
	if (x > inter->max)
		return inter->max;
	return x;
}
