/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events-camera-movement.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 18:39:49 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/09 22:40:51 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "rendering.h"
#include "events.h"
#include "gui.h"
#include "window.h"
#include "libft.h"

int	toggle_camera_movement(int keycode)
{
	t_scene	*scn;

	if (keycode != KEY_1)
		return (0);

	scn = get_scene();
	if (scn->input_flags & CAMERA_MODE)
	{
		set_input_event(CAMERA_MODE, UNACTIVE_FLG);
		render_image(scn, scn->win);
		printf(":: Camera Movement mode OFF\n");
	}
	else
	{
		set_input_event(CAMERA_MODE, ACTIVE_FLG);
		render_image(scn, scn->win);
		printf(":: Camera Movemente mode ON\n");
	}
	return (0);
}

int	move_camera(int keycode)
{
	t_scene		*scn;
	t_camera	*cam;

	scn = get_scene();
	cam = &get_scene()->camera;
	if (!(scn->input_flags & CAMERA_MODE))
		return (0);
	mlx_clear_window(scn->win->mlx, scn->win->mlx_win);
	cam_displace_horizontal(cam, keycode, 1.0f);
	cam_displace_vertical(cam, keycode, 1.0f);
	init_camera(&scn->camera);
	init_viewport(scn, scn->win);
	render_image(scn, scn->win);
	render_gui(scn);
	return (0);
}

int	zoom_camera(int keycode)
{
	t_scene		*scn;
	t_camera	*cam;

	scn = get_scene();
	if (!input_is_active(CAMERA_MODE))
		return (0);
	cam = &get_scene()->camera;
	if (keycode == KEY_FOV_UP && (cam->fovH - 10.0f) >= 10.0f)
		cam->fovH -= 10;
	if (keycode == KEY_FOV_DOWN && (cam->fovH + 10.0f) <= 101.0f)
		cam->fovH += 10;
	init_camera(&scn->camera);
	init_viewport(scn, scn->win);
	render_image(scn, scn->win);
	render_gui(scn);
	return (0);
}

// static int	get_depth_input(char **depth)
// {
// 	int		indx;	
// 	char	*value;

// 	indx = 0;
// 	value = NULL;
// 	printf("Input a valid depth (>1 && <10000):");
// 	while (indx == 0)
// 	{
// 		snprintf(value, 128, "CAMERA DEPTH:");
// 		if (!value)
// 			return (0);
// 		indx = ft_atoi(value);
// 		if (indx > 1 && indx < 100000)
// 			return ((*depth = value), 0);
// 		printf("Incorrect value, try again:");
// 	}
// 	return (0);
// }

// int	path_tracing_depth(int keycode)
// {
// 	t_scene		*scn;
// 	t_camera	*cam;
// 	char		*depth;

// 	scn = get_scene();
// 	if (keycode == KEY_2)
// 		return (0);
// 	set_input_event(STOP_INPUT_LAYER, ACTIVE_FLG);
// 	cam = &scn->camera;
// 	depth = NULL;
// 	if (!get_depth_input(&depth))
// 		return (0);
// 	init_camera(&scn->camera);
// 	init_viewport(scn, scn->win);
// 	render_image(scn, scn->win);
// 	mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
// 		H_pad + 20, color(255, 0, 0).clr, depth);
// 	depth = ft_itoa(cam->max_depth);
// 	// mlx_string_put(scn->win->mlx, scn->win->mlx_win, W_pad,
// 	// 	H_pad + 30, color(255, 0, 0).clr, depth);
// 	memfree((void *)&depth);
// 	set_input_event(STOP_INPUT_LAYER, UNACTIVE_FLG);	
// 	return (0);
// }