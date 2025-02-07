/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entities.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 15:29:18 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/27 13:36:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "error-handler.h"
#include "memory-handler.h"
#include "scene.h"
#include "libft.h"
#include "logger.h"

static void	required_entities(t_scene *scene, int flag)
{
	if (flag == REQ_CAMERA)
	{
		if (!scene->required_ents)
			scene->required_ents = REQ_CAMERA;
		else if (scene->required_ents == REQ_AMBIENT)
			scene->required_ents = REQ_FULL;
		else
			err_rt_file_format("more than one camera.");
	}
	if (flag == REQ_AMBIENT)
	{
		if (!(scene->required_ents))
			scene->required_ents = REQ_AMBIENT;
		else if (scene->required_ents == REQ_CAMERA)
			scene->required_ents = REQ_FULL;
		else
			err_rt_file_format("more than one ambient light.");
	}
}

void	create_ambient_light(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	required_entities(scene, REQ_AMBIENT);
	line += skip_spaces((char *)line);
	scene->alight.intensity = get_double((char *)line, 10, &offset);
	if (!in_range_dbl(scene->alight.intensity, 0.0, 1.0)
		|| line[offset] == ',' || offset == -1)
		err_rt_file_format("wrong ambient light format [range].");
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&scene->alight.rgb, (char *)line, &offset)
		|| !in_range_rgb(scene->alight.rgb, 0, 255))
		err_rt_file_format("wrong ambient light format [rgb].");
	line += skip_spaces((char *)&line[offset]);
	if (line[offset])
		err_rt_file_format("Error: Invalid input detected.");
}

void	create_camera(t_scene *scene, const char *line)
{
	int	offset;

	offset = 0;
	scene->camera.fovH = -1;
	required_entities(scene, REQ_CAMERA);
	if (set_vec3(&scene->camera.pos, (char *)line, &offset))
		err_rt_file_format("wrong camera format [xyz].");
	scene->camera.lookfrom = scene->camera.pos;
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&scene->camera.axis, (char *)line, &offset)
		|| !in_range_vec3(scene->camera.axis, -1.0, 1.0))
		err_rt_file_format("wrong camera format [normal].");
	scene->camera.lookat = normalize_v3(scene->camera.axis);
	offset += skip_spaces((char *)&line[offset]);
	update_line_offset((char **)&line, &offset);
	if (*line)
		scene->camera.fovH = get_double((char *)line, 10, &offset);
	if (line[offset] == ',' || !in_range_dbl(scene->camera.fovH, 0.0, 180.0)
		|| offset == -1)
		err_rt_file_format("wrong camera format [FOVH].");
	line += skip_spaces((char *)&line[offset]);
	if (line[offset])
		err_rt_file_format("Error: Invalid input detected.");
}

void	create_light_src(t_scene *scene, const char *line)
{
	t_light	*light;
	int		offset;

	offset = 0;
	light = (t_light *)xmalloc(sizeof(t_light));
	if (set_vec3(&light->pos, (char *)line, &offset))
		err_rt_file_format("wrong source light format [xyz].");
	update_line_offset((char **)&line, &offset);
	line += skip_spaces((char *)line);
	light->brghtnss = get_double((char *)line, 10, &offset);
	if (!in_range_dbl(light->brghtnss, 0.0, 1.0)
		|| offset == -1)
		err_rt_file_format("wrong source light format [BRGHTNSS].");
	line += offset;
	offset = 0;
	if (set_rgb(&light->rgb, (char *)line, &offset)
		|| !in_range_rgb(light->rgb, 0, 255) || offset == -1)
		err_rt_file_format("wrong source light format [rgb].");
	scene->num_lights++;
	add_node_to(&scene->lights, (void *)light, LIGHT);
	line += skip_spaces((char *)&line[offset]);
	if (line[offset])
		err_rt_file_format("Error: Invalid input detected.");
}
