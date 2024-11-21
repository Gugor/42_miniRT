/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colours.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 18:25:40 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 20:45:05 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOURS_H
#define COLOURS_H

# include "mrt-math.h"

typedef struct s_color
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int);
}	t_color;

typedef struct s_acolor
{
	unsigned int r;
	unsigned int g;
	unsigned int b;
	unsigned int a;
	uint32_t (*normalize)(unsigned int, unsigned int, unsigned int, unsigned int);
}	t_acolor;


#endif
