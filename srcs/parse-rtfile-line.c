/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-rtfile-line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:55:46 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/19 17:34:01 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

/**
* @brief It verifies if the buffer has a '\n'.
* A line is a string that starts from beginning of buffer until first newline
* or the end of the buffer.
* @param buff `{char *}` a pointer to the buffer.
* @returns `{size_t}`
* `the size of the buffer`
* `0 in case buffer is empty or doesn't exists`
*/
int verify_newline(char *buff)
{
	int size;

	size = skip_spaces(buff);
	while (buff[++size] && buff[size] != '\n')
		;;
	if (buff[size] == '\n')
		return (1);
	return (0);
}

/**
* @brief It finds the entity id in the buffer passed and return it integer id.
* NOTE: The id returned is the index of the array that stores the identifier ids in
* scene struct (`scene->entity_ids[]`). There is an `enum` called `ent_id`
* @returns `{int}`
* the entity id [0 - (NUM_ENTITIES - 1)]
*/
int     find_entity_id(char *buff)
{
        t_scene *scene;
        int     len;
        int     indx;

        scene = get_scene();
        len = 0;
        indx = -1;
        while (buff[len] && buff[len] != ' ')
                len++;
        while (scene->entity_ids[++indx])
                if (ft_strncmp(scene->entity_ids[indx], buff, len) == 0)
                        return (indx);
        return (-1);
}


/**
* @brief It extracts a line form a buffer, and updates the buffer with
* the remaining after line extraction.
* @param line `{char *}` a pointer to the container to copy the line.
* @param buff `{char *}` a pointer to the buffer where to extract the line from.
* @returns `{void}`
*/
void extract_line(char *line, char **buff)
{
	size_t	end;
	char	*remaining[BUFF_SIZE];
	int	ret;

	end = -1;
	ret = 0;
	while (*buff[++end] && *buff[end] != '\n')
		;;
	ft_strlcpy(line, *buff, end);
	ft_strlcpy((char *)remaining, buff[end], ft_strlen(*buff) - end); 
	free(*buff);
	ft_strlcpy(*buff, (const char *)remaining, ft_strlen((const char *)remaining));
}

/**
* @brief It parse a line and transform it into an entitie of the scene.
* @param line `{char *}` a pointer to the line to parse.
* @param scene `{t_scene *}` a pointer to the scene structure.
* @returns `{void}`
*/
void parse_rtfile_line(char *line, t_scene *scene)
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

