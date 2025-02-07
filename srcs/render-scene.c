/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render-scene.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:43:51 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 18:24:45 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rendering.h"
#include "ray.h"
#include "libft.h"
#include "shapes.h"
#include "shape-maths.h"
#include "time.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int *)dst = color;
}

static void	print_viewport_info(t_window *win)
{
	printf("	=> Viewport U[%f,%f,%f]\n", win->viewport_u.x,
		win->viewport_u.y, win->viewport_v.z);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x,
		win->viewport_v.y, win->viewport_v.z);
	printf("	=> Viewport Delta U[%f,%f,%f]\n", win->pixel_delta_u.x,
		win->pixel_delta_u.y, win->pixel_delta_u.z);
	printf("	=> Viewport Delta V[%f,%f,%f]\n", win->pixel_delta_v.x,
		win->pixel_delta_v.y, win->pixel_delta_v.z);
}

/**
 * @brief 
 * Sky Blue: 20, 109, 252 White Sky: 247, 250, 255
 */
void	render_image(t_scene *scn, t_window *win)
{
	int			samples;
	t_ivec2		pix_pos;
	t_ray		ray;
	t_color		new_color;

	pix_pos.x = -1;
	pix_pos.y = -1;
	print_viewport_info(win);
	while (++pix_pos.y < win->img_height)
	{
		while (++pix_pos.x < win->img_width)
		{
			new_color = color(0, 0, 0);
			samples = -1;
			while (++samples < scn->camera.samples_per_pixel)
			{
				ray = get_ray(win, &scn->camera, &pix_pos);
				new_color.clr = ray_color(&ray, scn->camera.max_depth).clr;
			}
			my_mlx_pixel_put(&win->img, pix_pos.x, pix_pos.y, new_color.clr);
		}
		pix_pos.x = -1;
	}
}

static void	print_create_light(t_light *lght)
{
	printf("=> Created Light:  \n");
	printf("	Pos: [%f,%f,%f]\n", lght->pos.x, lght->pos.y, lght->pos.z);
	printf("	BRGTNSS: %f\n", lght->brghtnss);
	printf("	RGB: [%hhu,%hhu,%hhu]\n", lght->rgb.r,
		lght->rgb.g, lght->rgb.b);
}

void	render_scene(t_scene *scn)
{
	int		elapsed;
	char	*render_time;
	t_lst	*lights;
	t_light	*lght;

	elapsed = 0;
	printf("=> Rendering Scene(%p)...\n", scn);
	scn->start_render_tme = get_current_time('m');
	lights = scn->lights;
	lght = NULL;
	while (lights)
	{
		lght = (t_light *)lights->cnt;
		print_create_light(lght);
		lights = lights->next;
	}
	render_image(scn, scn->win);
	elapsed = get_elapsed_time(scn->start_render_tme, 'm');
	render_time = ft_itoa(elapsed);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
	printf("Image rendered[%dms][%ds][%d:%dmins]\n", elapsed,
		(int)(elapsed * 0.001), (int)((elapsed * 0.001) / 60),
		(int)(elapsed * 0.001) - (int)(60 * (int)((elapsed * 0.001) / 60)));
	memfree((void *)&render_time);
}
