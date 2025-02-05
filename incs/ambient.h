/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ambient.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 17:23:37 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/24 17:23:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AMBIENT_H
# define AMBIENT_H

# include "colours.h"

typedef struct s_ambient
{
	double	intensity;
	t_color	rgb;
}	t_ambient;

t_color			ambient_light_calc(t_color clr, t_ambient *alight);

#endif
