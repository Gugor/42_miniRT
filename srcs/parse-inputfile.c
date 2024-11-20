/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-inputfile.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 15:27:43 by hmontoya         ###   ########.fr       */
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
*
int	read_rtfile_to_scene(int fd, t_scene *scene)
{
	char		line[BUFF_SIZE + 1];
	char		*buff;
	ssize_t		bytes_read;
	unsigned int	len;

	bytes_read = 1;
	len = 0;
	ft_memset((char *)&line, '\0', BUFF_SIZE + 1);
	while ((bytes_read = read(fd, &line, BUFF_SIZE)) > 0)
	{
		line[BUFF_SIZE] = '\0';
		printf("Line: %s\n", line);
		buff = ft_strjoin(&buff[len], (char *)line);
		len += skip_spaces((char *)&buff);
		while (buff[++len] && buff[len] == '\n')
			continue;
		if (!buff[len] && len >= BUFF_SIZE)
			return (-1);	//line too long
		extract_line((char *)line, &buff);
		parse_rtfile_line((char *)line, scene);	
	}
	free(buff);
	if (bytes_read < 0)
		return (-2); //error_reading file
	return (0);
}*/ 

/**
* @brief It parse rt file and create entities.
*/
int	read_rtfile_to_scene(int fd, t_scene *scene)
{
	char	*line;
	int	start;

	line = NULL;
	start = 0;
	while ((line = get_next_line(fd)))
	{
		start = skip_spaces(line);
		if(line[start] == '\n')
		{
			free(line);
			continue;
		}
		parse_rtfile_line(line, scene);
		free_simple((void *)&line);
	}
	return (0);
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
