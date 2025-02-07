/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-light-managing.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 13:41:28 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 15:08:01 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "events.h"
#include "scene.h"

int select_light(int keycode)
{

	if (keycode != KEY_1)
		return (0);
	t_scene *scn;

	scn = get_scene();
	return (0);
	
}