/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config-flags-manager.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:17:52 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 18:50:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "events.h"
#include "scene.h"

void set_config_flag(int mask, int condition)
{
	static int	*config_flags;

	config_flags = &get_scene()->config_flags;
	if (condition == 0)
	{
		*config_flags |= mask;
		return ;
	}
	if (condition == 1)
	{
		*config_flags &= ~mask;
		return ;
	}
	if (condition == 2)
	{
		*config_flags &= ~mask;
		*config_flags |= mask;
		return ;
	}
}

void set_inactive_incompatible_flags(int *masks)
{
	(void) masks;
	//Unset incompatible flags.
}
