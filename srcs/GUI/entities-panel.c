/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entities-panel.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 17:09:20 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:29:15 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "gui.h"
#include "events.h"
#include "libft.h"

void	show_camera_movement_panel(t_scene *scn)
{
	int		speed;
	char	lable[MAX_BUFFER];
	int		item_num;
	int		menu_pos;

	item_num = 0;
	menu_pos = (H_pad + ITEM_HEIGHT) * 2;
	speed = 10;
	if (scn->input_flags & CAMERA_MODE)
	{
		snprintf(lable, MAX_BUFFER, ":: CAMERA MOVEMENT - [%.2f,%.2f,%.2f]",
			scn->camera.lookfrom.x, scn->camera.lookfrom.y,
			scn->camera.lookfrom.z);
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			menu_pos, 0xFFFFFF, lable);
		snprintf(lable, MAX_BUFFER, " | SPEED:%i", speed);
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			(H_pad + ITEM_HEIGHT) * ++item_num + menu_pos, 0xFFFFFF, lable);
		ft_bzero(lable, MAX_BUFFER);
		snprintf(lable, MAX_BUFFER, " | ZOOMx%i [FOV:%i]",
			(int)(scn->camera.fovV / 10), (int)scn->camera.fovV);
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			(H_pad + ITEM_HEIGHT) * ++item_num + menu_pos, 0xFFFFFF, lable);
	}
}

void	show_shades_mode_panel(t_scene *scn)
{
	char	lable[MAX_BUFFER];
	int		item_num;
	int		menu_offset;
	int		item_height;

	item_height = ITEM_HEIGHT;
	item_num = 1;
	menu_offset = 1;
	ft_bzero(lable, MAX_BUFFER);
	if ((scn->input_flags & SHADES_MODE))
	{
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			(H_pad + item_height) * item_num * menu_offset,
			0xFFFFFF, ":: SHADES_MODE: BOTW");
	}
	else
	{
		mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
			(H_pad + item_height) * item_num * menu_offset, 0xFFFFFF,
			":: SHADES_MODE: DIFFUSE");
	}
}

void	show_render_time(t_scene *scn)
{
	char	lable[MAX_BUFFER];
	int		item_height;

	item_height = ITEM_HEIGHT;
	ft_bzero(lable, MAX_BUFFER);
	snprintf(lable, MAX_BUFFER, "Image rendered in %.4fs",
		scn->end_render_tme / 1000.0f);
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
		scn->win->img_height - item_height, 0xFFFFFF, lable);
}

int	render_gui(void *data)
{
	t_scene	*scn;

	scn = data;
	show_camera_movement_panel(scn);
	show_shades_mode_panel(scn);
	show_render_time(scn);
	return (0);
}
