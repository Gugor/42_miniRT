/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 17:04:25 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "mrt-math.h"

int	main(int ac, char **av)
{
	char		*filename;
	t_scene		scene;

	if (ac != 2)
		return (1);

	filename = av[1];
	init_scene_data(&scene);
	parse_rtfile(filename);
	printf("Filename: %s\n", filename);
	return (0);
}
