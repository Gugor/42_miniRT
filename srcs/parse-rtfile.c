/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-inputfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 19:10:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "file.h"
#include "parsing.h"
#include "error-handler.h"
#include "libft.h"
#include "get_next_line.h"

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
* @brief It parse rt file and create entities.
*/
int	read_rtfile_to_scene(int fd, t_scene *scene)
{
	char	*line;
	int		start;

	line = NULL;
	start = 0;
	line = get_next_line(fd);
	while (line)
	{
		start = skip_spaces(line);
		if (line[start] == '\n')
		{
			memfree((void *)&line);
			continue ;
		}
		if (line[ft_strlen(line) - 1] == '\n')
			line[ft_strlen(line) - 1] = '\0';
		parse_rtfile_line(line, scene);
		memfree((void *)&line);
		line = get_next_line(fd);
	}
	return (0);
}

/**
* @brief It parse the data form an .rt file into the t_scene structure 
* statically by `scene_storage()`.
* @param filename `{const char*}` the pat
* @returns `{int}`
* `0 no errors`
* `>0 for errors`
*/
int	parse_rtfile(const char *rt_path)
{
	t_scene	*scene;

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
