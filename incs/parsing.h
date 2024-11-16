/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:58:35 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 19:49:17 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with the parsing of the program and/or input/output files
* We can see if input/output parsing is too long for one header.
*/
#ifndef PARSING_H
#define PARSING_H

#include <unistd.h>

#define BUFF_SIZE 1024

int		is_rt_file(const char *filename);
int		parse_inputfile(const char *filename);
int		parse_ambient_light(const char *line);
int		parse_light_source(const char *line);
int		parse_plane(const char *line);
int		parse_sphere(const char *line);
int		parse_cylinder(const char *line);
int		read_entities(int fd, t_scene *scene);
void		parse_entities(char *buff, t_scene *scene);

int		is_scene_entity(const char *str);
#endif
