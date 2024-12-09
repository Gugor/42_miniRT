/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/08 18:50:25 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "maths.h"
#include "vectors.h"

void init_limits(double *lim[2], double min, double max)
{
	*lim[0] = min;
	*lim[1] = max;	
}

double degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}