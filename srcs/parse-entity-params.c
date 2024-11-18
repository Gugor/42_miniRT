/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entity-params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:11:19 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 19:59:20 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "string.h"
#include "scene.h"

double get_double(const char *line, int base, int *outsize)
{
	long double	num;
	int		indx;
	int		insize;
	int		neg;

	indx = -1;
	num = 0;
	insize = 0;
	neg = 0;
	if (line[0] == '-')
		neg = -1;		
	while (line[++indx] && line[indx] != '.')
		num = num * 10 + (line[indx] - 48);
	if (line[indx] == '.')
        	indx++;	
	insize += indx;
	while (line[++indx] && line[indx] != '.' && ft_isspace(line[indx]))
	{
		base *= 10;
		num += (line[indx] - 48) / base;
	}
	insize += indx;
	if (outsize)
		*outsize += insize;
	return (num * neg);
}

/**
* @brief It search for a vec3 format inside of a string.
* @param 
*/
void set_vec3(t_vec3 *vec3, const char *line, int *outsize)
{
	int	indx;
	int	commas;

	indx = -1;
	commas = 0;
	while (line[++indx] && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ',' || !ft_isdigit(line[indx + 1])))
			return (NULL);
		commas++;
	}
	if (commas != 2)
		return (NULL);
	indx = 0;
	vec3->x = get_double(line[indx], 10, indx);
	vec3->y = get_double(line[++indx], 10, indx);
	vec3->z = get_double(line[++indx], 10, indx);
	if (outsize)
		*outsize += indx + commas;
}

