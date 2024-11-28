/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 12:43:23 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error-handler.h"
#include "memory-handler.h"
#include "scene.h"
#include "libft.h"
#include "logger.h"

void	create_ambient_light(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	printf("=> Create Ambient Light: \"%s\" \n", line);
	if (!(scene->required_ents & REQ_AMBIENT))
		err_rt_file_format("more than one ambient light.");
	scene->alight.range = get_double((char *)line, 10, &offset);
	if (!in_range_dbl(scene->alight.range, 0.0, 1.0)
		|| line[offset] == ',' || offset == -1)
		err_rt_file_format("wrong ambient light format [range].");
	printf("	Range: %f\n", scene->alight.range);
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&scene->alight.rgb, (char *)line, &offset)
		|| !in_range_rgb(scene->alight.rgb, 0, 255))
	{
		printf("	Error RGB[%d,%d,%d]\n", scene->alight.rgb.r, scene->alight.rgb.g, scene->alight.rgb.b);
		err_rt_file_format("wrong ambient light format [rgb].");
	}
	printf("	RGB: [%hhu,%hhu,%hhu]\n", scene->alight.rgb.r, scene->alight.rgb.g, scene->alight.rgb.b);
	scene->required_ents |= REQ_AMBIENT;
}

void	create_camera(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	printf("=> Create Camera: \"%s\" \n", line);
	if (!(scene->required_ents & REQ_CAMERA))
		err_rt_file_format("more than one ambient light.");
	if (set_vec3(&scene->camera.pos, (char *)line, &offset))
		err_rt_file_format("wrong camera format [xyz].");
	printf("	Pos: [%f,%f,%f]\n", scene->camera.pos.x, scene->camera.pos.y, scene->camera.pos.z);
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&scene->camera.axis, (char *)line, &offset)
		|| !in_range_vec3(scene->camera.axis, -1.0, 1.0))
	{
		printf("	Error Axis: [%f,%f,%f]\n", scene->camera.axis.x, scene->camera.axis.y, scene->camera.axis.z);
		err_rt_file_format("wrong camera format [normal].");
	}
	printf("	Axis: [%f,%f,%f]\n", scene->camera.axis.x, scene->camera.axis.y, scene->camera.axis.z);
	line += offset;
	offset = 0;
	scene->camera.fovH = get_double((char *)line, 10, &offset);
	if (line[offset] == ',' || !in_range_dbl(scene->camera.fovH, 0.0, 180.0)
		|| offset == -1)
		err_rt_file_format("wrong  camera format [FOVH].");
	printf("	FoVH: %f\n", scene->camera.fovH);
	scene->required_ents |= REQ_CAMERA;
}

void	create_light_src(t_scene *scene, const char *line)
{
	t_light	*light;
	int		offset;

	offset = 0;
	light = (t_light *)xmalloc(sizeof(t_light));
	printf("=> Create Light: \"%s\" \n", line);
	if (set_vec3(&light->pos, (char *)line, &offset))
		err_rt_file_format("wrong source light format [xyz].");
	printf("	Pos: [%f,%f,%f]\n", light->pos.x, light->pos.y, light->pos.z);
	update_line_offset((char **)&line, &offset);
	light->brghtnss = get_double((char *)line, 10, &offset);
	if (!light || !in_range_dbl(light->brghtnss, 0.0, 180.0) || offset == -1)
		err_rt_file_format("wrong source light format [BRGHTNSS].");
	printf("	BRGTNSS: %f\n", light->brghtnss);
	line += offset;
	offset = 0;
	if (set_rgb(&light->rgb, (char *)line, &offset)
		|| !in_range_rgb(light->rgb, 0, 255) || offset == -1)
		err_rt_file_format("wrong source light format [rgb].");
	printf("	RGB: [%hhu,%hhu,%hhu]\n", light->rgb.r, light->rgb.g, light->rgb.b);
	scene->num_lights++;
	add_node_to(&scene->lights, (void *)light, LIGHT);
}
