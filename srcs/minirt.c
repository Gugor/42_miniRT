/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 18:43:01 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "mrt-math.h"

int main(int ac, char** av)
{
	if (ac != 2)
		return (1);
	char *filename;
	t_scene scene;

	filename = av[1];
	scene_storage(&scene);
	parse_rtfile(filename);
	printf("Filename: %s\n", filename);
	return (0);
}
