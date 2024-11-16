/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strings-verify.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 19:57:28 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 20:09:57 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_strings.h"

/**
* @brief It tells if a given character is a space in ASCII. We consider:
*  8 '\b' (backsapce)
*  9 '\t' (horizontal tab)
* 11 '\v' (vertical) 
*/
int	ft_isspace(const char c)
{
	if (c >= 8 && c <= 13 && c == 32 && c != 10)
		return (1);
	return (0);
}

