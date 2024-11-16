/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ERROR_HANDLER_H
#define ERROR_HANDLER_H

#include <string.h>
#include <errno.h>

enum errorsnum 
{
	SUCCESS,
	ERR_NO_RT_EXT,
	ERR_FILE_NO_OPEN,	
};

void		err_no_rt_extension(void);
void		err_wrong_rt_file_format(void);
void		err_rt_file_not_open(const int err);

#endif
