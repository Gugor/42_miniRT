/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/18 18:39:48 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include "mrt-math.h"

typedef struct s_color
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint32_t (*normalize)(uint8_t, uint8_t, uint8_t);
}	t_color;

typedef struct s_acolor
{
	uint8_t r;
	uint8_t g;
	uint8_t b;
	uint8_t a;
	uint32_t (*normalize)(uint8_t, uint8_t, uint8_t, uint8_t);
}	t_acolor;


#endif
