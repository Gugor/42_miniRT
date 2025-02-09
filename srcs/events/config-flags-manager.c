/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config-flags-manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:17:52 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/09 22:13:55 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"
#include "scene.h"

void	set_input_event(int mask, int condition)
{
	static int	*input_flags;

	input_flags = &get_scene()->input_flags;
	if (condition == 0)
	{
		*input_flags |= mask;
		return ;
	}
	if (condition == 1)
	{
		*input_flags &= ~mask;
		return ;
	}
	if (condition == 2)
	{
		*input_flags &= ~mask;
		*input_flags |= mask;
		return ;
	}
}
