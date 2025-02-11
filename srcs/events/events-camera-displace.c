/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-camera-displace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:29:14 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:08:34 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "events.h"

void	cam_displace_horizontal(t_camera *cam, int dir, double amount)
{
	if (dir == KEY_UP)
	{
		cam->lookfrom.y += cam->lookat.y * amount;
		cam->lookfrom.x += cam->lookat.x * amount;
		cam->lookfrom.z += cam->lookat.z * amount;
	}
	if (dir == KEY_DOWN)
	{
		cam->lookfrom.y -= cam->lookat.y * amount;
		cam->lookfrom.x -= cam->lookat.x * amount;
		cam->lookfrom.z -= cam->lookat.z * amount;
	}
}

void	cam_displace_vertical(t_camera *cam, int dir, double amount)
{
	if (dir == KEY_LEFT)
	{
		cam->lookfrom.y -= cam->u.y * amount;
		cam->lookfrom.x -= cam->u.x * amount;
		cam->lookfrom.z -= cam->u.z * amount;
	}
	if (dir == KEY_RIGHT)
	{
		cam->lookfrom.y += cam->u.y * amount;
		cam->lookfrom.x += cam->u.x * amount;
		cam->lookfrom.z += cam->u.z * amount;
	}
}
