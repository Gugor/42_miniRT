/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log-file.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:11:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 18:02:35 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "logger.h"
# include <sys/time.h>


/**
* @brief It creates a filename for the logger with the current timestamp.
* @param 
*/ 
int create_log_file(char *filename)
{
	return 		
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
		log->fd = create_log_file(filename);
	}
	logger_storage(log);
}

/**
* @brief It stores statically the logger structure, and returns it
* every time called.
* @param log `{t_logger *}` a pointer to the logger data structure.
* @returns {t_logger *)
* `a pointer to t_logger *`
* `NULL in case logger has not being stored`
*/
int logger_storage(t_logger *log)
{
	static t_logger *in_log = NULL;
	if (!log)
		in_log = log;
	return (in_log);
}

void	log(const char *msg, int newline)
{
	
}
