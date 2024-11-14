/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strings.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:56:52 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:13:24 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_strlen(const char *str)
{
	int indx;
	
	indx = -1;
	while (str[++indx])
		;;
	return (indx);
}

int ft_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2)
	{
		if (*s1 == *s2)
			return (0);
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}
