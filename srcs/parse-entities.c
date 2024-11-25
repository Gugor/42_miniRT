/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/25 20:31:43 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error-handler.h"
#include "scene.h"
#include "libft.h"
#include "logger.h"

void	create_ambient_light(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	printf("=> Create Ambient Light: %s \n", line);
	if (!(scene->required_ents & REQ_AMBIENT))
		err_rt_file_format("more than one ambient light.");
	line += skip_spaces((char *)line);
	if (!line || !ft_isdigit(*line))
		err_rt_file_format("0 wrong ambient light format.");
	scene->alight.range = get_double((char *)&line[offset], 10, &offset);
	if (!scene->alight.range || !in_range_dbl(scene->alight.range, 0.0, 1.0))
		err_rt_file_format("wrong ambient light format [range].");
	if (set_rgb(&scene->alight.rgb, (char *)&line[offset], &offset) 
			|| !in_range_rgb(scene->alight.rgb, 0, 255))
	{
		printf("	Error RGB[%d,%d,%d]\n", scene->alight.rgb.r, scene->alight.rgb.g, scene->alight.rgb.b);
		err_rt_file_format("wrong ambient light format [rgb].");
	}
	scene->required_ents |= REQ_AMBIENT;
}

void	create_camera(t_scene *scene, const char *line)
{
	int offset;

	offset = 0;
	printf("=> Create Camera: %s \n", line);
	line += skip_spaces((char *)line);
	if (set_vec3(&scene->camera.pos, (char *)&line[offset], &offset))
		err_rt_file_format("wrong camera format [xyz].");
	printf("	Pos: [%f,%f,%f]\n", scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
	printf("	Line[%i]: %s\n", offset, &line[offset] );
	if (set_vec3(&scene->camera.axis, (char *)&line[offset], &offset)
		|| !in_range_vec3(scene->camera.axis, -1.0, 1.0))
	{
		printf("	Error Axis: [%f,%f,%f]\n", scene->camera.axis.x, scene->camera.axis.y, scene->camera.axis.z);
		err_rt_file_format("wrong camera format [normal].");
	}
	printf("	Axis: [%f,%f,%f]\n", scene->camera.axis.x, scene->camera.axis.y, scene->camera.axis.z);
	printf("	Line[%i]: %s\n", offset, &line[offset] );
	scene->camera.fovH = get_double((char *)line, 10, &offset);
	if (!in_range_dbl(scene->camera.fovH, 0.0, 180.0))
		err_rt_file_format("wrong  camera format [FOVH].");
	printf("	FoVH: %f\n", scene->camera.fovH);
	scene->required_ents |= REQ_CAMERA;
}

void	create_light_src(t_scene *scene, const char *line)
{
	(void)scene;
	(void)line;
	/*t_light *light;

	light = get_light(scene->lights, scene->num_lights)
	line += skip_spaces((char *)line);
	if (!line || !ft_isdigit(*line))
		err_rt_file_format("wrong camera format.");
	if (set_vec3(&scene->camera.pos, (char *)line, NULL))
		err_rt_file_format("wrong camera format [xyz].");
	if (!scene->lights[scene->num_lights - 1] || !in_range_dbl(scene->camera.fovH, 0.0, 180.0))
		err_rt_file_format("wrong ambien light format [FOVH].");
	if (set_vec3(&scene->camera.axis, (char *)line, NULL)
		|| !in_range_vec3(scene->camera.axis, -1.0, 1.0))
		err_rt_file_format("wrong camera format [normal].");
	scene->camera.fovH = get_double((char *)line, 10, NULL);*/
}
