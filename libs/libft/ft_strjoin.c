/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpietrza <mpietrza@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 16:51:05 by hmontoya          #+#    #+#             */
/*   Updated: 2024/09/18 16:00:20 by mpietrza         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*newstr;
	int		len1;
	int		len2;
	int		i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = 0;
	if (!s2)
		return ((char *)s1);
	newstr = (char *)ft_calloc(len1 + len2 + 1, sizeof(char));
	if (!newstr)
		return (NULL);
	while (s1[i])
	{
		newstr[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i])
	{
		newstr[len1 + i] = s2[i];
		i++;
	}
	return (newstr);
}
