/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:41 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/09 21:24:06 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "gui.h"
#include "events.h"
#include "rendering.h"
#include "memory-handler.h"

bool check_flags(int flags)
{
	if ((get_scene()->input_flags & flags))
		return (printf("Input not allowed\n"), 1);
	else
		return (printf("Input\n"), 0);
}

bool	input_is_active(int flag)
{
	if (get_scene()->input_flags & flag)
		return (1);
	else
		return (0);
}

int	close(int keycode)
{
	if (keycode != KEY_ESCAPE && keycode != 0)
		return (0);
	clear_scene();
	printf("Window closed...\n");
	exit(0);
	return (0);
}

/**
 * @brief It toggles between hard and soft shades.
 */
int	toggle_hard_shades_mode(int keycode)
{
	t_scene		*scn;

	if (keycode != KEY_0)
		return (0);
	scn = get_scene();
	if (scn->input_flags & SHADES_MODE)
	{
		set_input_event(SHADES_MODE, UNACTIVE_FLG);
		render_image(scn, scn->win);
		mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
		// render_gui(scn);
		printf(":: Shade mode OFF\n");
	}
	else
	{
		set_input_event(SHADES_MODE, ACTIVE_FLG);
		render_image(scn, scn->win);
		// render_gui(scn);
		printf(":: Shade mode ON\n");
	}
	return (0);
}

int	on_key_pressed(int keycode)
{
	printf("== Keycode %i\n", keycode);
	toggle_hard_shades_mode(keycode);
	close(keycode);
	toggle_camera_movement(keycode);
	move_camera(keycode);
	zoom_camera(keycode);
	return (0);
}

void	listen_events(void)
{
	t_scene	*scn;

	scn = get_scene();
	mlx_hook(scn->win->mlx_win, KeyPress, KeyPressMask, on_key_pressed, NULL);
	mlx_hook(scn->win->mlx_win, ON_DESTROY, SubstructureNotifyMask,
		close, NULL);
}
