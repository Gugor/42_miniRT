/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 15:36:58 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/22 14:29:28 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include "libft.h"
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

char	*chr_memfree(char **s);
char	*get_next_line(int fd);
char	*read_line(int fd, char *buffer);
char	*get_nline(char **buf);
//Utils
ssize_t	ft_strlenss(char *s);
char	*ft_bufjoin(char *b1, char *b2);
char	*ft_strcut(char *s, ssize_t size);
#endif
