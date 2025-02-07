/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rt-file.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:50:43 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/16 14:50:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "error-handler.h"
#include "file.h"

/**
* @brief It opens the file rt and throws an error otherwise.
*/
int	open_rt(const char *rt_path)
{
	int	fd;

	fd = open(rt_path, O_RDONLY);
	if (fd < 0)
	{
		err_rt_file_not_open(errno);
		exit(ERR_FILE_NO_OPEN);
	}
	return (fd);
}
