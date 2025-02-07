/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:50:22 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/12 13:35:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "parsing.h"
#include "vectors.h"
#include "rendering.h"
#include "memory-handler.h"
#include "error-handler.h"

void	print_struct_sizes(void)
{
	printf("t_scene size: %li\n", sizeof(t_scene));
	printf("t_vec3 size: %li\n", sizeof(t_vec3));
	printf("t_vec2 size: %li\n", sizeof(t_vec2));
	printf("t_color size: %li\n", sizeof(t_color));
	printf("t_lst size: %li\n", sizeof(t_lst));
	printf("\n");
	printf("t_camera size: %li\n", sizeof(t_camera));
	printf("t_ambient size: %li\n", sizeof(t_ambient));
	printf("t_light size: %li\n", sizeof(t_light));
	printf("t_plane size: %li\n", sizeof(t_plane));
	printf("t_sphere size: %li\n", sizeof(t_sphere));
	printf("t_cylinder size: %li\n", sizeof(t_cylinder));
	printf("\n");
	printf("t_material size: %li\n", sizeof(t_material));
	printf("\n");
	printf("t_reqents size: %li\n", sizeof(t_reqents));
	printf("t_entid size: %li\n", sizeof(t_entid));
	printf("e_errorsnum size: %li\n", sizeof(t_errorsnum));
	printf("\n");
}

int	main(int ac, char **av)
{
	char		*filename;
	t_scene		scene;
	t_window	win;

	if (ac != 2)
	{
		printf("Error: no .rt file provided\n");
		return (1);
	}
	print_struct_sizes();
	filename = av[1];
	printf("Filename: %s\n", filename);
	init_scene_data(&scene, &win);
	parse_rtfile(filename);
	init_window(&scene);
	printf("Open window...\n");
	render_scene(&scene);
	mlx_loop(scene.win->mlx);
	clear_scene();
	return (0);
}
