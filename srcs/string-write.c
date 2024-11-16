/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string-write.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:47:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:11:04 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

/**
* @brief It write a sting in a given file descriptor.
* @param fd `{int}` a file descriptor to write to.
* @param str `{const char *}` a pointer to the string to write.
* @returns `{void}`
*/
void ft_putstr_fd(int fd, const char *str)
{
	if (!str)
		return ;
	while(*str)
		write(fd, str++, 1);
}

