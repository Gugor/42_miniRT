/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:45:41 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/05 21:37:59 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "window.h"
#include "events.h"
#include "rendering.h"
#include "memory-handler.h"

int close(int keycode)
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
int toggle_hard_shades_mode(int keycode)
{
	t_scene		*scn;
	
	if (keycode != KEY_ZERO)
		return (0);
	scn = get_scene();
	
	if (scn->shades_mode)
	{
		scn->shades_mode = 0;
		dprintf(2, ":: Shade mode OFF\n");
	}
	else
	{
		scn->shades_mode = 1;
		dprintf(2, ":: Shade mode ON\n");
	}
	mlx_clear_window(scn->win->mlx, scn->win->mlx_win);
	render_image(scn, scn->win);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
	// mlx_loop(scn->win->mlx);
	return (0);
}

int on_key_pressed(int keycode)
{
	dprintf(2, "Keycode %i\n", keycode);
	toggle_hard_shades_mode(keycode);
	close(keycode);
	return (0);
}

void listen_events(void)
{
	t_scene *scn;

	scn = get_scene();
	mlx_hook(scn->win->mlx_win, KeyPress, KeyPressMask, on_key_pressed, NULL);
	mlx_hook(scn->win->mlx_win, ON_DESTROY, SubstructureNotifyMask, close, NULL);
}
