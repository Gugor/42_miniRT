/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-rtfile-line.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 13:55:46 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/25 19:29:38 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "libft.h"

/**
* @brief It finds the entity id in the buffer passed and return it integer id.
* NOTE: The id returned is the index of the array that stores the identifier ids in
* scene struct (`scene->entity_ids[]`). There is an `enum` called `ent_id`
* @returns `{int}`
* the entity id [0 - (NUM_ENTITIES - 1)]
*/
int	find_entity_id(char *buff)
{
	t_scene	*scene;
	char	*id;
	int		indx;
	int		len;

	scene = get_scene();
	indx = -1;
	len = 0;
	while (buff[len] && !ft_isspace(buff[len]))
		len++;
	id = ft_substr(buff, 0, len);
	while (scene->entity_ids[++indx])
	{
		if (ft_strcmp(scene->entity_ids[indx], id) == 0)
		{
			memfree((void *)&id);
			return (indx);
		}
	}
	memfree((void *)&id);
	return (-1);
}


/**
* @brief It parse a line and transform it into an entitie of the scene.
* @param line `{char *}` a pointer to the line to parse.
* @param scene `{t_scene *}` a pointer to the scene structure.
* @returns `{void}`
*/
void	parse_rtfile_line(char *line, t_scene *scene)
{
	int	ent_id;
	int id_offset;

	ent_id = find_entity_id(line);
	if (ent_id == -1)
	{
		//throw err and exit 
		printf("Wrong Id not entity found\n");
	}
	id_offset = ft_strlen(scene->entity_ids[ent_id]);
	scene->create_ent[ent_id](scene, &line[id_offset]);
}

