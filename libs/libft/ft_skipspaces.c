/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:24:47 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/19 19:51:42 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces(char *str)
{
	int	indx;

	indx = 0;
	while (str[indx] && ft_isspace(str[indx]))
		indx++;
	return (indx);
}
