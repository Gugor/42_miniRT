/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math-convertions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:05:30 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/11 20:06:26 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "maths.h"
#include "vectors.h"

double degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}