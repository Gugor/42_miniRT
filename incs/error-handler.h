/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error-handler.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:50:32 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLER_H
# define ERROR_HANDLER_H

# include <string.h>
# include <errno.h>
# include "vectors.h"

typedef enum e_errorsnum 
{
	SUCCESS,
	ERR_NO_RT_EXT,
	ERR_FILE_NO_OPEN,	
}	t_errorsnum;

void		err_no_rt_extension(void);
void		err_wrong_rt_file_format(void);
void		err_rt_file_not_open(const int err);
void		err_rt_file_format(const char *msg);
int			verify_axis(t_vec3 axis);
#endif
