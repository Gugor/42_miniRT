/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger-file.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:11:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 19:31:53 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"

int create_log_file(const char *path)
{
	int fd;
	
	if ((fd = open(path, O_CREATE | O_RDWR)) != -1)
	{
		printf("An error happend opening the file\n");
		return (1);
	}
}

/**
* @brief It initializes the logger structure to be used 
* during logging in this program
* @param log `{t_logger *}` a pointer to the logger structure to 
* initialize.
* @param filename `{char*}`(optional) a pointer representing
* the filename to use as stream to log to.
* @return `{int}`
* `0 no errors`
* `1 open file error`
* `2 write permission error`
*/
int	init_logger(t_logger *log, char *filename)
{
	//create
	if (!filename)
	{
		//create log filename
		//open log filename
		filename = create_log_file(filename);
	}
}

