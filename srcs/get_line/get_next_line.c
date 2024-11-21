/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 16:00:21 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 19:15:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*chr_memfree(char **s)
{
	if (s && *s)
		free(*s);
	*s = NULL;
	return (NULL);
}

char	*read_line(int fd, char *buffer)
{
	char	*chunk;
	ssize_t	bytes_read;

	bytes_read = 1;
	chunk = (char *)ft_calloc((BUFFER_SIZE + 1), sizeof(char));
	if (!chunk)
		return (chr_memfree(&buffer));
	while (bytes_read > 0 && !ft_strchr(chunk, '\n'))
	{
		bytes_read = read(fd, chunk, BUFFER_SIZE);
		if (bytes_read < 0 && !chr_memfree(&buffer))
			return (chr_memfree(&chunk));
		if (bytes_read > 0)
		{
			chunk[bytes_read] = '\0';
			buffer = ft_bufjoin(buffer, chunk);
			if (!buffer)
				return (chr_memfree(&chunk));
		}
	}
	chr_memfree(&chunk);
	if (!(*buffer))
		return (chr_memfree(&buffer));
	return (buffer);
}

char	*get_nline(char **buf)
{
	ssize_t	ln_size;
	char	*tmp;
	char	*line;

	ln_size = 0;
	tmp = NULL;
	while ((*buf)[ln_size] && (*buf)[ln_size] != '\n')
		ln_size++;
	if ((*buf)[ln_size] == '\n')
		ln_size++;
	line = ft_strcut(*buf, ln_size);
	if (!line)
		return (chr_memfree(buf));
	if ((*buf)[ln_size] != '\0')
	{
		tmp = ft_strcut(*buf + ln_size, ft_strlen(*buf) - (ln_size));
		if (!tmp && !chr_memfree(&line))
			return (chr_memfree(buf));
	}
	chr_memfree(buf);
	*buf = tmp;
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 0 || read(fd, 0, 0) < 0)
		return (chr_memfree(&buffer));
	line = NULL;
	if (!buffer)
	{
		buffer = (char *)malloc(1 * sizeof(char));
		if (!buffer)
			return (NULL);
		buffer[0] = '\0';
	}
	if (!ft_strchr(buffer, '\n'))
		buffer = read_line(fd, buffer);
	if (!buffer || !buffer[0])
		return (chr_memfree(&buffer));
	line = get_nline(&buffer);
	if (!line)
		return (chr_memfree(&buffer));
	return (line);
}
