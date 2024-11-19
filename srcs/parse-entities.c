/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/19 20:02:48 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error-handler.h"
#include "scene.h"
#include "libft.h"

void	create_ambient_light(t_scene *scene, const char *line)
{
	int	indx;

	if (!(scene->required_ents & REQ_AMBIENT))
		err_rt_file_format("more than one ambient light.");
	line += skip_spaces((char *)line);
	if (!line || !ft_isdigit(*line))
		err_rt_file_format("wrong ambien light format.");
	indx = -1;
	scene->alight.range = get_double((char *)line, 10, NULL);
	if (!scene->alight.range || !in_range_dbl(scene->alight.range, 0.0, 1.0))
		err_rt_file_format("wrong ambien light format [range].");
	if (set_rgb(&scene->alight.rgb, (char *)line, NULL)
		|| !in_range_rgb(scene->alight.rgb, 0, 255))
		err_rt_file_format("wrong ambien light format [rgb].");
	scene->required_ents |= REQ_AMBIENT;
}

void create_light_source(t_scene *scene, char *line){
	(void)scene;
	(void)line;
}

void create_camera(t_scene *scene, char *line)
{
	(void)scene;
	(void)line;
}

void create_entity(t_scene *scene, t_entid id, const char *line)
{
	switch (id)
	{
		case AMBIENT:
			create_ambient_light(scene, line);
			break;
		case LIGHT:
		//	create_light();
			break;
		case CAMERA:
		//	create_camera();
			break;
		case PLANE:
		//	create_plane();
			break;
		case SPHERE:
			//create_sphere();
			break;
		case CYLINDER:
			//create_cylinder();
			break;
		case OTHER:
			//create_ambient_light();
			break;
	}
}
