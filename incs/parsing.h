/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:35 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 19:58:09 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the parsing of the program and/or input/output files
* We can see if input/output parsing is too long for one header.
*/
#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>

# define BUFF_SIZE 1024

typedef enum e_ent_id
{
	AMBIENT,
	LIGHT,
	CAMERA,
	PLANE,
	SPHERE,
	CYLINDER,
	OTHER,
}	t_entid;


int		is_rt_file(const char *filename);
int		parse_rtfile(const char *filename);
int		parse_ambient_light(const char *line);
int		parse_light_source(const char *line);
int		parse_plane(const char *line);
int		parse_sphere(const char *line);
int		parse_cylinder(const char *line);
int		read_rtfile_to_scene(int fd, t_scene *scene);
void		parse_rtfile_line(char *entity, t_scene *scene);
void		create_entity(t_scene *scene, t_entid id, const char *line);
void		create_ambient_light(t_scene *scene, const char *line);

int			is_scene_entity(const char *str);
void		set_vec3(t_vec3 *vec3, const char *line, int *outsize);
double		get_double(const char *line, int base, int *outsize);
#endif
