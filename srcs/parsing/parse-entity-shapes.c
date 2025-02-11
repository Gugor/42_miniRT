/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entity-shapes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:49:48 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 14:00:37 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "scene.h"
#include "memory-handler.h"
#include "error-handler.h"
#include "shapes.h"
#include "libft.h"

void	create_plane(t_scene *scene, const char *line)
{
	t_plane	*plane;
	int		offset;

	offset = 0;
	plane = (t_plane *)xmalloc(sizeof(t_plane));
	if (set_vec3(&plane->pos, (char *)line, &offset))
		err_rt_file_format("wrong plane format [xyz]");
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&plane->axis, (char *)line, &offset)
		|| !in_range_vec3(plane->axis, -1, 1))
		err_rt_file_format("wrong plane format [normal]");
	plane->axis = normalize_v3(plane->axis);
	if (verify_axis(plane->axis))
		err_rt_file_format("wrong axis: cannot be [0,0,0]");
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&plane->rgb, (char *)line, &offset)
		|| !in_range_rgb(plane->rgb, 0, 255))
		err_rt_file_format("wrong plane format [rgb]");
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)plane, PLANE);
	verify_eol((char *)&line[offset]);
}

void	create_sphere(t_scene *scene, const char *line)
{
	t_sphere	*sphere;
	int			offset;

	offset = 0;
	sphere = (t_sphere *)xmalloc(sizeof(t_sphere));
	if (set_vec3(&sphere->pos, (char *)line, &offset))
		err_rt_file_format("wrong sphere format [xyz]");
	update_line_offset((char **)&line, &offset);
	sphere->rad = get_double((char *)line, 10, &offset);
	if (line[offset] == ',' || offset == -1 || sphere->rad < 0)
		err_rt_file_format("wrong sphere format [size]");
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&sphere->rgb, (char *)line, &offset)
		|| !in_range_rgb(sphere->rgb, 0, 255))
		err_rt_file_format("wrong sphere format [rgb]");
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)sphere, SPHERE);
	verify_eol((char *)&line[offset]);
}

void	create_cylinder(t_scene *scene, const char *line)
{
	t_cylinder	*cylinder;
	int			offset;

	offset = 0;
	cylinder = (t_cylinder *)xmalloc(sizeof(t_cylinder));
	if (set_vec3(&cylinder->pos, (char *)line, &offset))
		err_rt_file_format("wrong cylinder format [xyz]");
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&cylinder->axis, (char *)line, &offset)
		|| !in_range_vec3(cylinder->axis, -1, 1))
		err_rt_file_format("wrong cylinder format [normal]");
	cylinder->axis = normalize_v3(cylinder->axis);
	if (verify_axis(cylinder->axis))
		err_rt_file_format("wrong axis: cannot be [0,0,0]");
	update_line_offset((char **)&line, &offset);
	if (set_cylinder_size(&cylinder->size, (char *)line, &offset))
		err_rt_file_format("wrong cylinder format [size]");
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&cylinder->rgb, (char *)line, &offset)
		|| !in_range_rgb(cylinder->rgb, 0, 255))
		err_rt_file_format("wrong cylinder format [rgb]");
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)cylinder, CYLINDER);
	verify_eol((char *)&line[offset]);
}

void	create_square(t_scene *scene, const char *line)
{
	t_square	*square;
	int			offset;

	offset = 0;
	square = (t_square *)xmalloc(sizeof(t_square));
	if (set_vec3(&square->pos, (char *)line, &offset))
		err_rt_file_format("wrong square format [xyz]");
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&square->axis, (char *)line, &offset))
		err_rt_file_format("wrong square format [axis]");
	square->axis = normalize_v3(square->axis);
	update_line_offset((char **)&line, &offset);
	if (set_cylinder_size(&square->size, (char *)line, &offset))
		err_rt_file_format("wrong square format [size]");
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&square->rgb, (char *)line, &offset)
		|| !in_range_rgb(square->rgb, 0, 255))
		err_rt_file_format("wrong square format [rgb]");
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)square, SQUARE);
	verify_eol((char *)&line[offset]);
}
