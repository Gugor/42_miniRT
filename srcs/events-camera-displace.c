/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-camera-displace.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 19:29:14 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/07 17:06:20 by hmontoya         ###   ########.fr       */
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
		dprintf(2, ":: Move camera up. Now in [%f,%f,%f]\n",
			cam->lookfrom.x, cam->lookfrom.y, cam->lookfrom.z);
	}
	if (dir == KEY_DOWN)
	{
		cam->lookfrom.y -= cam->lookat.y * amount;
		cam->lookfrom.x -= cam->lookat.x * amount;
		cam->lookfrom.z -= cam->lookat.z * amount;
		dprintf(2, ":: Move camera down. Now in [%f,%f,%f]\n",
			cam->lookat.x, cam->lookfrom.y, cam->lookfrom.z);
	}
}

void	cam_displace_vertical(t_camera *cam, int dir, double amount)
{
	if (dir == KEY_LEFT)
	{
		cam->lookfrom.y -= cam->u.x * amount;
		cam->lookfrom.x -= cam->u.x * amount;
		cam->lookfrom.z -= cam->u.z * amount;
		dprintf(2, ":: Move camera left. Now in [%f,%f,%f]\n",
			cam->lookfrom.x, cam->lookfrom.y, cam->lookfrom.z);
	}
	if (dir == KEY_RIGHT)
	{
		cam->lookfrom.y += cam->u.x * amount;
		cam->lookfrom.x += cam->u.x * amount;
		cam->lookfrom.z += cam->u.z * amount;
		dprintf(2, ":: Move camera right. Now in [%f,%f,%f]\n",
			cam->lookfrom.x, cam->lookfrom.y, cam->lookfrom.z);
	}
}