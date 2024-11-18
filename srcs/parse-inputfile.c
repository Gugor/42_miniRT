/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-inputfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 19:19:10 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "file.h"
#include "parsing.h"
#include "ft_strings.h"
#include "error-handler.h"


/**
* @brief 
*/
int	is_rt_file(const char *filename)
{
	int	size;

	size = ft_strlen(filename);
	if (filename[size - 3] == '.')
	{
		if (filename[size -2] == 'r' && filename[size -1] == 't')
			return (1);
		if (filename[size -2] == 'R' && filename[size -1] == 'T')
			return (1);
	}
	return (0);
}


/**
* @brief It finds the entity id in the buffer passed and return it integer id.
* NOTE: The id returned is the index of the array that stores the identifier ids in
* scene struct (`scene->entity_ids[]`). There is an `enum` called `ent_id`
* @returns `{int}`
* the entity id [0 - (NUM_ENTITIES - 1)]
*/
int	find_entity_id(char *buff)
{
	t_scene *scene;
	int	len;
	int	indx;

	scene = get_scene();
	len = 0;
	indx = -1;
	while (buff[len] && buff[len] != ' ')
		len++;
	while (scene->entity_ids[++indx])
	{
		if (ft_strncmp(scene->entity_ids[indx], buff, len) == 0)
			return (indx);
	}
	return (-1);
}

/**
* @brief It parse a line and transform it into an entitie of the scene.
*/
void parse_rt_file_line(char *line, t_scene *scene)
{
	int indx;
	int ent_id;

	indx = skip_spaces(line);
	line += indx; 
	ent_id = find_entity_id(line);
	if (ent_id == -1)
		//throw err and exit
	create_entity(scene, ent_id, line);
}

/**
* @brief It patse rt file and create entities.
*/
int	read_rtfile_to_scene(int fd, t_scene *scene)
{
	char		*buff[BUFF_SIZE];
	ssize_t		bytes_read;
	unsigned int	len;

	bytes_read = 0;
	len = 0;
	while ((bytes_read = read(fd, buff, BUFF_SIZE)) != 0)
	{
		parse_rtfile_line(buff, scene);	
	}
} 


/**
* @brief It parse the data form an .rt file into the t_scene structure statically by `scene_storage()`.
* @param filename `{const char*}` the pat
* @returns `{int}`
* `0 no errors`
* `>0 for errors`
*/
int	parse_rtfile(const char *rt_path)
{
	t_scene *scene;

	scene = get_scene();
	if (!is_rt_file(rt_path))
	{
		err_no_rt_extension();
		return (1);
	}
	else
	{
		//open_fil
		scene->rtfd = open_rt(rt_path);
		read_rtfile_to_scene(scene->rtfd, scene);
		return (0);
	}
}
