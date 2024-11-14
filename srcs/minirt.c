/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:12:56 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parsing.h"
#include "mrt-math.h"

int main(int ac, char** av)
{
	if (ac != 2)
		return (1);
	char *filename;

	filename = av[1];
	parse_inputfile(filename);
	printf("Filename: %s\n", filename);
	return (0);
}
