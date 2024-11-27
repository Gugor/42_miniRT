/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:35 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/27 18:09:10 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the parsing of the program and/or input/output files
* We can see if input/output parsing is too long for one header.
*/
#ifndef PARSING_H
# define PARSING_H

# include <unistd.h>
# include "scene.h"

# define BUFF_SIZE 80



/*****************************************************************************/
/*               RT_file src/parse-rtfile.c                                  */
int			is_rt_file(const char *filename);
int			parse_rtfile(const char *filename);
int			read_rtfile_to_scene(int fd, t_scene *scene);

/*               RTfile Line  src/parse-rtfile-line.c                                               */
void		parse_rtfile_line(char *entity, t_scene *scene);
void		parse_rtfile_line(char *line, t_scene *scene);
int			find_entity_id(char *buff);

/*               RTfile Line                                                 */
void		create_ambient_light(t_scene *scene, const char *line);
void		create_camera(t_scene *scene, const char *line);
void		create_light_src(t_scene *scene, const char *line);
void		create_plane(t_scene *scene, const char *line);
void		create_sphere(t_scene *scene, const char *line);
void		create_cylinder(t_scene *scene, const char *line);

int			set_vec3(t_vec3 *vec3, const char *line, int *outsize);
int			set_rgb(t_color *rgb, const char *line, int *outsize);
double		get_double(const char *line, long double base, int *outsize);
uint8_t		get_uint8(const char *line, uint16_t base, int *outsize);
int			set_cylinder_size(t_vec2 *size, const char *line, int *outsize);
#endif
