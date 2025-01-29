/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/19 18:55:18 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "error-handler.h"

/**
* @brief 
*/
void	err_no_rt_extension(void)
{
	ft_putstr_fd(2, "Error: this is not a valid file. You need to provide"
		" a file with a '.rt' extension\n");
	exit(101);
}

/**
* @brief 
*/
void	err_rt_file_not_open(const int err)
{
	ft_putstr_fd(2, "Error: ");
	ft_putstr_fd(2, strerror(err));
	ft_putstr_fd(2, "\n");
	exit(101);
}

void	err_rt_file_format(const char *msg)
{
	ft_putstr_fd(2, "Error: rt file: ");
	ft_putstr_fd(2, (char *)msg);
	ft_putstr_fd(2, "\n");
	exit(101);
}

/**
* @brief
*/
void	err_wrong_rt_file_format(void)
{
	ft_putstr_fd(2, "Error: this file has not a valid format."
		" Please provide a valid formatted file.\n");
	exit(101);
}
