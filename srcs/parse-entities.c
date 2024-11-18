/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 19:29:06 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"

void create_ambient_light(t_scene *scene, const char *line)
{
	int indx;
	if (!(scene->required_ents & REQ_AMBIENT)) 
		//error building scene: more than one ambient lights
	line += skip_spacess(line);
	if (!line || !ft_isdigit(line))
		//throw err and exit;
	indx = -1;
	while (line[++indx])
	{
		scene->alight.range = get_double(line);
		if (!scene->alight.range)
			//throw err and exit;
		scene->alight.rgb = vec3_to_rgb(get_vec3(line))
		if (!scene->alight.rgb)
			//throw err and exit;
	}
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
			create_ambient_light();
			break;
		case LIGHT:
			create_light();
			break;
		case CAMERA:
			create_camera();
			break;
		case PLANE:
			create_plane();
			break;
		case SPHERE:
			create_sphere();
			break;
		case CYLINDER:
			create_cylinder();
			break;
		case OTHER:
			//create_ambient_light();
			break;
	}
}
