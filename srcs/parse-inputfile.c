/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-inputfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "ft_strings.h"

int	is_rt_file(const char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (filename[size - 3] == '.')
	{
		if (filename[size -2] == 'r' && filename[size -1] == 't')
			return (1);
		if (filename[size -2] == 'R' && filename[size -1] == 'T')
			return (1);
	}
	return (0);
}

int	parse_inputfile(const char *filename)
{
	if (is_rt_file(filename))
	{
		printf("is a rt file");
		return (1);
	}
	else
	{
		printf("is NOT a rt file");
		return (0);
	}
	
}
