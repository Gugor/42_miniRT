/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-entity-shapes.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:49:48 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/03 17:23:58 by hmontoya         ###   ########.fr       */
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
	plane->id = scene->num_shapes;
	printf("=> Create Plane: \"%s\" \n", line);
	if (set_vec3(&plane->pos, (char *)line, &offset))
		err_rt_file_format("wrong plane format [xyz]");
	printf("	Pos: [%f,%f,%f]\n", plane->pos.x, plane->pos.y, plane->pos.z);
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&plane->axis, (char *)line, &offset)
		|| !in_range_vec3(plane->axis, -1, 1))
		err_rt_file_format("wrong plane format [normal]");
	printf("	Normal: [%f,%f,%f]\n", plane->axis.x, plane->axis.y, plane->axis.z);
	plane->axis = normalize_v3(plane->axis);
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&plane->rgb, (char *)line, &offset)
		|| !in_range_rgb(plane->rgb, 0, 255))
		err_rt_file_format("wrong plane format [rgb]");
	printf("	RGB: [%hhu,%hhu,%hhu]\n", plane->rgb.r, plane->rgb.g, plane->rgb.b);
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)plane, PLANE);
}

void	create_sphere(t_scene *scene, const char *line)
{
	t_sphere	*sphere;
	int			offset;

	offset = 0;
	sphere = (t_sphere *)xmalloc(sizeof(t_sphere));
	sphere->id = scene->num_shapes;
	printf("=> Create Sphere: \"%s\" \n", line);
	if (set_vec3(&sphere->pos, (char *)line, &offset))
		err_rt_file_format("wrong sphere format [xyz]");
	printf("	Pos: [%f,%f,%f]\n", sphere->pos.x, sphere->pos.y, sphere->pos.z);
	update_line_offset((char **)&line, &offset);
	sphere->rad = get_double((char *)line, 10, &offset);
	if (line[offset] == ',' || offset == -1 || sphere->rad < 0)
		err_rt_file_format("wrong sphere format [size]");
	printf("	Radius: %f\n", sphere->rad);
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&sphere->rgb, (char *)line, &offset)
		|| !in_range_rgb(sphere->rgb, 0, 255))
		err_rt_file_format("wrong sphere format [rgb]");
	printf("	RGB: [%i,%i,%i]\n", (sphere->rgb.clr >> 16) & 0xFF, (sphere->rgb.clr >> 8) & 0xFF, (sphere->rgb.clr) & 0xFF);
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)sphere, SPHERE);
}

void	create_cylinder(t_scene *scene, const char *line)
{
	t_cylinder	*cylinder;
	int	offset;

	offset = 0;
	cylinder = (t_cylinder *)xmalloc(sizeof(t_cylinder));
	cylinder->id = scene->num_shapes;
	printf("=> Create Cylinder: \"%s\" \n", line);
	if (set_vec3(&cylinder->pos, (char *)line, &offset))
		err_rt_file_format("wrong cylinder format [xyz]");
	printf("	Pos: [%f,%f,%f]\n", cylinder->pos.x, cylinder->pos.y, cylinder->pos.z);
	update_line_offset((char **)&line, &offset);
	if (set_vec3(&cylinder->axis, (char *)line, &offset))
		err_rt_file_format("wrong cylinder format [normal]");
	printf("	Axis: [%f,%f,%f]\n", cylinder->axis.x, cylinder->axis.y, cylinder->axis.z);
	cylinder->axis = normalize_v3(cylinder->axis);
	printf("	Norm.Axis: [%f,%f,%f]\n", cylinder->axis.x, cylinder->axis.y, cylinder->axis.z);
	update_line_offset((char **)&line, &offset);
	if (set_cylinder_size(&cylinder->size, (char *)line, &offset))
		err_rt_file_format("wrong cylinder format [size]");
	printf("	Size: [%f,%f]\n", cylinder->size.x, cylinder->size.y);
	update_line_offset((char **)&line, &offset);
	if (set_rgb(&cylinder->rgb, (char *)line, &offset) || !in_range_rgb(cylinder->rgb, 0, 255))
		err_rt_file_format("wrong cylinder format [rgb]");
	printf("	RGB: [%i,%i,%i]\n", (cylinder->rgb.clr >> 16) & 0xFF, (cylinder->rgb.clr >> 8) & 0xFF, (cylinder->rgb.clr) & 0xFF);
	scene->num_shapes++;
	add_node_to(&scene->shapes, (void *)cylinder, CYLINDER);
}
