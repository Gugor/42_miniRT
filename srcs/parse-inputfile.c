/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-inputfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:04 by hmontoya         ###   ########.fr       */
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

int	is_valid_entity(char *buff)
{
	t_scene *scene;
	int	indx;

	scene = get_scene();
	while (scene->entity_ids[indx])
	{
		if (ft_strcmp(scene->entity_ids[indx]))
	}
}

/**
* @brief It parse a line and transform it into an entitie of the scene.
*/
void parse_entities(char *buff, t_scene *scene)
{
	int indx;

	indx = skip_spaces(buff);
	buff += indx; 
	if (is_valid_entity(buff))
	{

	}
}

/**
* @brief It patse rt file and create entities.
*/
int	read_entities(int fd, t_scene *scene)
{
	char		*buf[BUFF_SIZE];
	ssize_t		bytes_read;

	bytes_read = 0;
	while ((bytes_read = read(fd, buf, BUFF_SIZE)) != 0)
	{
		parse_entities(buff, t_scene *scene);	
	
	}
} 


/**
* @brief It parse the data form an .rt file into the t_scene structure statically by `scene_storage()`.
* @param filename `{const char*}` the pat
* @returns `{int}`
* `0 no errors`
* `>0 for errors`
*/
int	parse_inputfile(const char *rt_path)
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
		parse_entities();
		return (0);
	}
}
