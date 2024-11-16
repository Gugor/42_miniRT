/* ************************************************************************** */
/*                                                        :::      ::::::::   */
/*   string-iterate.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:28 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:09:57 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

/**
* @brief
*/
int	skip_spaces(const char *str)
{
	int indx;
	
	indx = 0;
	while (ft_isspace(str[indx]))
		indx++;
	return (0);
}
