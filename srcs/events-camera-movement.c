/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-camera-movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:39:49 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 19:51:46 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "events.h"
#include "ui.h"
#include "window.h"

int toggle_camera_movement(int keycode)
{

	if (keycode != KEY_1)
		return (0);
	t_scene *scn;
	// Desactivate uncompatible flags with this.
	scn = get_scene();
	if (scn->config_flags & CAMERA_MODE)
	{
		set_config_flag(CAMERA_MODE, UNACTIVE_FLG);
		render_image(scn, scn->win);
		dprintf(2, ":: Camera Movemente mode OFF\n");
	}
	else
	{
		set_config_flag(CAMERA_MODE, ACTIVE_FLG);
		render_image(scn, scn->win);
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			H_pad + 10, color(255, 0, 0).clr, "CAMERA MOVEMENT: ON");
		dprintf(2, ":: Camera Movemente mode ON\n");
	}
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
		return (0);
}

int move_camera(int keycode)
{
	t_scene *scn;
	t_camera *cam;

	
	scn = get_scene();
	cam = &get_scene()->camera;
	if (!(scn->config_flags & CAMERA_MODE) )
		return (0);
	cam_displace_horizontal(cam, keycode, 0.1f);
	cam_displace_vertical(cam, keycode, 0.1f);
	init_camera(&scn->camera);
	init_viewport(scn, scn->win);
	render_image(scn, scn->win);
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			H_pad + 10, color(255, 0, 0).clr, "CAMERA MOVEMENT: ON");
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);	
	return (0);
}

int	rotate_camera(int keycode)
{
	t_camera	*cam;
	t_interval	inter;

	if (!(get_scene()->config_flags & CAMERA_MODE))
		return (0);
	init_limits(&inter, -1.0f, 1.0f);
	cam = &get_scene()->camera;
	if (keycode == KEY_ROT_UP)
	{
		cam->lookat.y += 0.1;
		clamp(&inter, cam->lookat.y);
	}
	if (keycode == KEY_ROT_DOWN)
	{
		cam->lookat.y -= 0.1;
		clamp(&inter, cam->lookat.y);
	}
	if (keycode == KEY_ROT_LEFT)
	{
		cam->lookat.x += 0.1;
		clamp(&inter, cam->lookat.y);
	}
	if (keycode == KEY_ROT_RIGHT)
	{
		cam->lookat.z -= 0.1;
		clamp(&inter, cam->lookat.y);
	}
	return (0);
}

int	zoom_camera(int keycode)
{
	t_camera	*cam;

	cam = &get_scene()->camera;
	if (!(get_scene()->config_flags & CAMERA_MODE))
		return (0);
	if (keycode == KEY_FOV_UP)
		cam->fovH += 0.1;
	if (keycode == KEY_FOV_DOWN)
		cam->fovH -= 0.1;
	return (0);
}