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
#include "vectors.h"



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

double	get_double(const char *line, double base, int *outsize)
{
	double	num;
	int			indx;
	double	neg;

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

	indx = 0;
	indx += skip_spaces((char *)&line[0]);
	if (!ft_isdigit(line[indx]) && is_vec_format(&line[indx], VEC3))
		return (2);
	if (!ft_isdigit(line[indx]) && line[indx] != '-')
		return (2);
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

int	set_cylinder_size(t_vec3 *size, const char *line, int *outsize)
{
	int	indx;

	indx = skip_spaces((char *)&line[0]);
	size->x = get_double(&line[indx], 10, &indx);
	if (indx == -1)
		return (1);
	indx += skip_spaces((char *)&line[indx]);
	size->y = get_double(&line[indx], 10, &indx);
	size->z = size->y * 0.5;
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
	if (is_vec_format(&line[indx], VEC3))
		return (2);
	indx = skip_spaces((char *)&line[0]);
	if (line[indx] == '-')
		return (3);
	rgb->clr |= get_uint8(&line[indx], 10, &indx) << 16;
	if (indx == -1 || line[++indx] == '-')
		return (3);
	rgb->clr |= get_uint8(&line[indx], 10, &indx) << 8;
	if (indx == -1 || line[++indx] == '-')
		return (3);
	rgb->clr |= get_uint8(&line[indx], 10, &indx);
	if (indx == -1)
		return (3);
	if (outsize)
		*outsize += indx;
	return (0);
}
