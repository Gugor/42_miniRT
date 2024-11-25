/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entity-params.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 16:11:19 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/25 19:36:26by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "string.h"
#include "scene.h"
#include "libft.h"

static int is_chneg(const char *line, int *offset)
{
	if (line[0] == '-')
	{
		(*offset)++;
		return (-1);
	}
	return (1);
}

uint8_t	get_uint8(const char *line, uint8_t base, int *outsize)
{
	uint8_t	num;
	int		indx;
	int		offset;

	indx = -1;
	num = 0;
	offset = 0;
	if (is_chneg(line, &indx) == -1)	
		return (0);
	while (line[++indx] && line[indx] != ',')
		num = num * base + (line[indx] - 48);
	if (outsize)
		*outsize += indx + offset;
	return (num);
}

double	get_double(const char *line, long double base, int *outsize)
{
	long double	num;
	int			indx;
	int			offset;
	long double	neg;

	indx = -1;
	num = 0;
	offset = 0;
	neg = is_chneg(line, &indx);	
	if (neg == -1)
		offset++;
	while (line[++indx] && ft_isdigit(line[indx]))
		num = num * 10 + (line[indx] - 48);
	if (line[indx] != '.')
		return ((*outsize += offset + indx), (double)(num * neg));
	while (line[++indx] && ft_isdigit(line[indx]))
	{
		base *= 10;
		num += (line[indx] - 48) / base;
	}
	if (outsize)
		*outsize += indx + ++offset;
	return ((double)(num * neg));
}

/**
 * @brief It search for a vec3 format inside of a string.
 * @param
 */
int	set_vec3(t_vec3 *vec3, const char *line, int *outsize)
{
	int	indx;
	int	commas;

	indx = -1;
	commas = 0;
	printf("	    Vec3 BSP Line[0] = %s\n", &line[0]);
	*outsize = skip_spaces((char *)&line[*outsize]);
	indx += *outsize;
	printf("	    Vec3 Line[%i] = %s\n", indx + 1, &line[indx + 1]);
	while (line[++indx] && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ','
				|| !ft_isdigit(line[indx + 1])))
			return (1);
		if (line[indx] == ',')
			commas++;
	}
	if (commas != 2)
		return (2);
	indx = 0;
	vec3->x = get_double(&line[indx], 10, &indx);
	vec3->y = get_double(&line[++indx], 10, &indx);
	vec3->z = get_double(&line[++indx], 10, &indx);
	if (outsize)
		*outsize += indx;
	return (0);
}

/**
 * @brief It search for a vec3 format inside of a string.
 * @param
 */
int	set_rgb(t_color *rgb, const char *line, int *outsize)
{
	int	indx;
	int	commas;

	indx = -1;
	commas = 0;
	while (line[++indx] && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ','
				|| !ft_isdigit(line[indx + 1])))
			return (1);
		if (line[indx] == ',')
			commas++;
	}
	if (commas != 2)
		return (2);
	indx = 0;
	if (line[indx] == '-')	
		return (3);
	rgb->r = get_uint8(&line[indx], 10, &indx);
	if (line[++indx] == '-')	
		return (3);
	rgb->g = get_uint8(&line[indx], 10, &indx);
	if (line[++indx] == '-')	
		return (3);
	rgb->b = get_uint8(&line[indx], 10, &indx);
	printf("rgb[%u,%u,%u]\n", rgb->r, rgb->g, rgb->b);
	if (outsize)
		*outsize += indx + commas;
	return (0);
}
