/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render-scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:43:51 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:27:22 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "logger.h"
#include "ray.h"
#include "libft.h"
#include "shapes.h"
#include "shape-maths.h"
#include "time.h"
#include "gui.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

/**
 * @brief 
 * Sky Blue: 20, 109, 252 White Sky: 247, 250, 255
 */
void	render_image(t_scene *scn, t_window *win)
{
	t_ivec2		pix_pos;
	t_ray		ray;
	t_color		new_color;

	pix_pos.x = -1;
	pix_pos.y = -1;
	scn->start_render_tme = get_current_time('m');
	while (++pix_pos.y < win->img_height)
	{
		while (++pix_pos.x < win->img_width)
		{
			new_color = color(0, 0, 0);
			ray = get_ray(win, &scn->camera, &pix_pos);
			new_color.clr = ray_color(&ray, scn->camera.max_depth).clr;
			my_mlx_pixel_put(&win->img, pix_pos.x, pix_pos.y, new_color.clr);
		}
		pix_pos.x = -1;
	}
	scn->end_render_tme = get_elapsed_time(scn->start_render_tme, 'm');
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
}

void	render_scene(t_scene *scn)
{
	t_lst	*lights;
	t_light	*lght;

	lights = scn->lights;
	lght = NULL;
	while (lights)
	{
		lght = (t_light *)lights->cnt;
		log_create_light(lght);
		lights = lights->next;
	}
	mlx_loop_hook(scn->win->mlx, &render_gui, scn);
	log_vwp_data(scn->win);
	render_image(scn, scn->win);
	log_render_time(scn->end_render_tme);
}
