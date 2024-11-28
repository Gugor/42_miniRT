/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 12:14:49 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "mrt-math.h"
#include "memory-handler.h"


int	main(int ac, char **av)
{
	char		*filename;
	t_scene		scene;

	if (ac != 2)
	{
		printf("Error: no .rt file provided\n");
		return (1);
	}
	filename = av[1];
	printf("Filename: %s\n", filename);
	init_scene_data(&scene);
	parse_rtfile(filename);
	clear_scene();
	return (0);
}
