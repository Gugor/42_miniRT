/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 21:01:43 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error-handler.h"
#include "scene.h"
#include "libft.h"

void	create_ambient_light(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	if (!(scene->required_ents & REQ_AMBIENT))
		err_rt_file_format("more than one ambient light.");
	line += skip_spaces((char *)line);
	if (!line || !ft_isdigit(*line))
		err_rt_file_format("wrong ambien light format.");
	scene->alight.range = get_double((char *)line, 10, &offset);
	printf("Ambient light range: %f\n", scene->alight.range);
	if (!scene->alight.range || !in_range_dbl(scene->alight.range, 0.0, 1.0))
		err_rt_file_format("wrong ambien light format [range].");
	line += offset;
	line += skip_spaces((char *)line);
	printf("A-Light Start rgb:%s\n", line);
	if (set_rgb(&scene->alight.rgb, (char *)line, NULL)
		|| !in_range_rgb(scene->alight.rgb, 0, 255))
		err_rt_file_format("wrong ambien light format [rgb].");
	scene->required_ents |= REQ_AMBIENT;
}

void	create_camera(t_scene *scene, const char *line)
{
	if (!(scene->required_ents & REQ_CAMERA))
		err_rt_file_format("more than one ambient light.");
	line += skip_spaces((char *)line);
	if (!line || !ft_isdigit(*line))
		err_rt_file_format("wrong camera format.");
	if (set_vec3(&scene->camera.pos, (char *)line, NULL))
		err_rt_file_format("wrong camera format [xyz].");
	if (set_vec3(&scene->camera.axis, (char *)line, NULL)
		|| !in_range_vec3(scene->camera.axis, -1.0, 1.0))
		err_rt_file_format("wrong camera format [normal].");
	scene->camera.fovH = get_double((char *)line, 10, NULL);
	if (!scene->camera.fovH || !in_range_dbl(scene->camera.fovH, 0.0, 180.0))
		err_rt_file_format("wrong ambien light format [FOVH].");
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
