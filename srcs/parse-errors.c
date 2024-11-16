/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse-errors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"
#include "error-handler.h"

/**
* @brief 
*/
void err_no_rt_extension(void)
{
	ft_putstr_fd(2, "Error: this is not a valid file. You need to provide a file with a '.rt' extension\n");	
}

/**
* @brief 
*/
void err_rt_file_not_open(int err)
{
	ft_putstr_fd(2,"Error:");
	ft_putstr_fd(2, stderror(err));
	ft_putstr_fd(2,"\n");
}

/**
* @brief
*/
void	err_wrong_rt_file_format(void)
{
	ft_putstr_fd(2, "Error: this file has not a valid format. Please provide a valid formatted file.\n");	
}
