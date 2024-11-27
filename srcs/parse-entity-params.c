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

static int	is_chneg(const char *line, int *offset)
{
	if (line[0] == '-')
	{
		(*offset)++;
		return (-1);
	}
	return (1);
}

static int	verify_commas(const char *line)
{
	int	commas;
	int	indx;

	commas = 0;
	indx = 0;
	while (line[indx] && !ft_isspace(line[indx]))
	{
		if (line[indx] == ',' && (!line[indx + 1] || line[indx + 1] == ','
				|| !ft_isdigit(line[indx + 1])))
			return (1);
		if (line[indx++] == ',')
			commas++;
	}
	return (commas);
}

uint8_t	get_uint8(const char *line, uint16_t base, int *outsize)
{
	uint16_t	num;
	int			indx;

	indx = 0;
	num = 0;
	indx += skip_spaces((char *)&line[0]);
	if (is_chneg(line, &indx) == -1)
		return (0);
	while (line[indx] && ft_isdigit(line[indx]))
		num = num * base + (line[indx++] - 48);
	if (num > 255)
		return ((uint8_t)(*outsize = -1));
	if (line[indx] && !ft_isdigit(line[indx]) && line[indx] != ','
		&& !ft_isspace(line[indx]))
		return ((uint8_t)(*outsize = -1));
	if (outsize)
		*outsize += indx;
	return ((uint8_t)num);
}

double	get_double(const char *line, long double base, int *outsize)
{
	long double	num;
	int			indx;
	long double	neg;

	indx = 0;
	num = 0;
	indx += skip_spaces((char *)&line[0]);
	neg = is_chneg(&line[indx], &indx);
	while (line[indx] && ft_isdigit(line[indx]))
		num = num * 10 + (line[indx++] - 48);
	if (line[indx] != '.' && (ft_isspace(line[indx]) || !line[indx]))
		return ((*outsize += indx), (double)(num * neg));
	if (line[indx] == '.')
		++indx;
	while (line[indx] && ft_isdigit(line[indx]))
	{
		num += (line[indx++] - 48) / base;
		base *= 10;
	}
	if (line[indx] && !ft_isdigit(line[indx]) && line[indx] != ','
		&& !ft_isspace(line[indx]))
		return ((double)(*outsize = -1));
	if (outsize)
		*outsize += indx;
	return ((double)(num * neg));
}



/**
 * @brief It search for a vec3 format inside of a string.
 * @param
 */
int	set_vec3(t_vec3 *vec3, const char *line, int *outsize)
{
	int		indx;
	int		commas;

	indx = 0;
	commas = 0;
	indx += skip_spaces((char *)&line[0]);
	if (verify_commas(&line[indx]) != 2)
		return (2);
	indx = 0;
	vec3->x = get_double(&line[indx], 10, &indx);
	if (indx == -1)
		return (1);
	vec3->y = get_double(&line[++indx], 10, &indx);
	if (indx == -1)
		return (1);
	vec3->z = get_double(&line[++indx], 10, &indx);
	if (indx == -1)
		return (1);
	if (outsize)
		*outsize += indx;
	return (0);
}

int	set_cylinder_size(t_vec2 *size, const char *line, int *outsize)
{
	int	indx;

	indx = skip_spaces((char *)&line[0]);
	size->x = get_double(&line[indx], 10, &indx);
	if (indx == -1)
		return (1);
	indx += skip_spaces((char *)&line[indx]);
	size->y = get_double(&line[indx], 10, &indx);
	if (indx == -1)
		return (1);
	if (outsize)
		*outsize += indx;
	return (0);
}

/**
 * @brief It search for a vec3 format inside of a string.
 * @param
 */
int set_rgb(t_color *rgb, const char *line, int *outsize)
{
	int indx;

	indx = 0;
	indx += skip_spaces((char *)&line[0]);
	if (verify_commas(&line[indx]) != 2)
		return (2);
	indx = skip_spaces((char *)&line[0]);
	if (line[indx] == '-')
		return (3);
	rgb->r = get_uint8(&line[indx], 10, &indx);
	if (indx == -1 || line[++indx] == '-')
		return (3);
	rgb->g = get_uint8(&line[indx], 10, &indx);
	if (indx == -1 || line[++indx] == '-')
		return (3);
	rgb->b = get_uint8(&line[indx], 10, &indx);
	if (indx == -1)
		return (3);
	if (outsize)
		*outsize += indx;
	return (0);
}
