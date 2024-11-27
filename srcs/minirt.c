/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/27 19:16:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "mrt-math.h"
#include "memory-handler.h"

void print_lst(t_lst *lst)
{
	while (lst)
	{
		if (lst->type == AMBIENT)
			t_ambient *node = (t_ambient *)lst->cnt;
		if (lst->type == CAMERA)
			t_camera *node = (t_camera *)lst->cnt;
		if (lst->type == LIGHT)
			t_light *node = (t_light *)lst->cnt;
		if (lst->type == PLANE)
			t_plane *node = (t_plane *)lst->cnt;
		if (lst->type == SPHERE)
			t_sphere *node = (t_sphere *)lst->cnt;
		if (lst->type == CYLINDER)
			t_cylinder *node = (t_cylinder *)lst->cnt;
		
	}
}

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
	init_scene_data(&scene);
	parse_rtfile(filename);
	clear_scene();
	printf("Filename: %s\n", filename);
	return (0);
}
