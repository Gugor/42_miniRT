/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   multithread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:51:44 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/13 00:22:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-handler.h"
#include "scene.h"
#include "rendering.h"

void	*render_thread(void *arg)
{
	t_rm_tile	*tl;
	t_scene		*scn;

	tl = (t_rm_tile *)arg;
	scn = tl->scn;
	scn->start_render_tme = get_current_time('m');
	tl->px_pos.y = tl->start_y;
	while (++tl->px_pos.y < scn->win->img_height)
	{
		tl->px_pos.x = tl->start_x;
		while (++tl->px_pos.x <= tl->end_x)
		{
			tl->new_color = color(0, 0, 0);
			tl->ray = get_ray(scn->win, &scn->camera, &tl->px_pos);
			tl->new_color.clr = ray_color(&tl->ray, scn->camera.max_depth).clr;
			my_mlx_pixel_put(&scn->win->img, tl->px_pos.x, tl->px_pos.y,
				tl->new_color.clr);
		}
	}
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
	scn->end_render_tme = get_elapsed_time(scn->start_render_tme, 'm');
	return (NULL);
}

int	get_num_threads(t_rdata *rd)
{
	rd->num_tiles = sysconf(_SC_NPROCESSORS_ONLN);
	// rd->num_tiles = 16;
	return (rd->num_tiles);
}

void	init_tile(t_rm_tile *tile, t_rdata *rd, t_scene *scn)
{
	tile->start_x = rd->indx * rd->tl_width;
	tile->end_x = (rd->indx + 1) * rd->tl_width;
	tile->start_y = 0;
	tile->end_y = scn->win->img_height;
	tile->buffer = scn->win->img.img;
	tile->scn = scn;
	tile->rmut = &rd->rmut;
}

/**
 * @brief it divides the image to render into equal columns, as many as 
 * processor cores are permitted for the CPU;
*/
int	render_multithreaded(void *data)
{
	t_scene		*scn;
	pthread_t	*threads;
	t_rm_tile	*tiles;
	t_rdata		rd;

	scn = data;
	rd.tl_width = scn->win->img_width / get_num_threads(&rd);
	tiles = (t_rm_tile *)xmalloc(sizeof(t_rm_tile) * rd.num_tiles);
	threads = (pthread_t *)xmalloc(sizeof(pthread_t) *rd.num_tiles);
	rd.indx = -1;
	while (++rd.indx < rd.num_tiles)
	{
		init_tile(&tiles[rd.indx], &rd, scn);
	    if (rd.indx == rd.num_tiles - 1)
			tiles[rd.indx].end_x = scn->win->img_width;
		pthread_create(&threads[rd.indx], NULL, render_thread, &tiles[rd.indx]);
	}
	rd.indx = -1;
	while (++rd.indx < rd.num_tiles)
	    pthread_join(threads[rd.indx], NULL);
	free(tiles);
	free(threads);
	return (0);
}
