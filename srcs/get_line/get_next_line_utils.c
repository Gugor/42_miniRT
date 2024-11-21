/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/20 16:06:54 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 19:15:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

ssize_t	ft_strlenss(char *s)
{
	ssize_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcut(char *s, ssize_t size)
{
	char	*dup;
	ssize_t	i;

	i = 0;
	dup = ft_calloc((size + 1), sizeof(char));
	if (!dup)
		return (NULL);
	while (i < size)
	{
		dup[i] = (char)s[i];
		i++;
	}
	return (dup);
}

char	*ft_bufjoin(char *b1, char *b2)
{
	char	*newstr;
	ssize_t	i;
	ssize_t	j;
	ssize_t	b1_len;
	ssize_t	b2_len;

	if ((!b1 && !b2))
		return (NULL);
	i = -1;
	j = -1;
	b1_len = ft_strlen(b1);
	b2_len = ft_strlen(b2);
	newstr = (char *)ft_calloc((b1_len + b2_len + 1), sizeof(char));
	if (!newstr)
		return (chr_memfree(&b1));
	while (b1[++i])
		*(newstr + i) = b1[i];
	while (b2[++j])
		*(newstr + i + j) = b2[j];
	chr_memfree(&b1);
	return (newstr);
}
