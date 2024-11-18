/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:28 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 18:49:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRINGS_H
#define FT_STRINGS_H

#include <unistd.h>

/******************************************************************************/
/*			String Verifiy        		                      */
int		ft_strcmp(const char *s1, const char *s2);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		ft_strlen(const char *str);
int		ft_isspace(const char c);

/*			String Iterate	        		              */
int		skip_spaces(const char *str);

/*			String Write	        		              */
void		ft_putstr_fd(int fd, const char *str);

#endif
