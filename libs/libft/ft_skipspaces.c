/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skipspaces.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 16:24:47 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/19 16:27:49 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	skip_spaces(const char *str)
{
	int indx;

	indx = 0;
	while (ft_isspace(str[indx]))
		indx++;
	return (0);
}
