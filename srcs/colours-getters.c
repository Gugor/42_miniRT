/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours-getters.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/18 18:34:20 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/18 18:38:16 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "colours.h"

uint8_t	get_r(t_color c)
{
	return ((c.clr >> 16) & 0xFF);
}

uint8_t	get_g(t_color c)
{
	return ((c.clr >> 8) & 0xFF);
}

uint8_t	get_b(t_color c)
{
	return ((c.clr) & 0xFF);
}

