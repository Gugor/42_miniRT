

#include "scene.h"
#include "rendering.h"
#include "memory-handler.h"

void	render_thread(void *data)
{
	t_scene			*scn;
	t_rtile			*tile;
	t_ray			ray;
	t_color			new_color;

	while (tile->iy < scn->win->img_height)
	{
		while (++tile.ix < scn->win->img_width)
		{
			new_color = color(0, 0, 0);
			ray = get_ray(scn->win, &scn->camera, &pix_pos);
			new_color.clr = ray_color(&ray, scn->camera.max_depth).clr;
			my_mlx_pixel_put(&win->img, pix_pos.x, pix_pos.y, new_color.clr);
		}
		pix_pos.x = -1;
	}
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win,
		scn->win->img.img, 0, 0);
}

void	get_render_tile_size(t_scene *scn, t_renderdata *rdata)
{
	rdata->num_procss = get_nprocs();
	rdata->tile_width = scn->win->img_width / scn->num_procs;

}

void	render_multythread(t_scene *scn)
{
	t_renderdata	*rdata;
	int				indx;
	t_rtile			*tiles;

	rdata = scn->renddata;
	get_render_tile_size(&rdata);
	tiles = xmalloc(rdata->num_tiles);
	while (++indx < rdata->num_tiles)
	{
		tiles[indx] = (t_rtiles)
		{
			.start_x = i * rdata->tile_with,
			.end_x = (i + 1) * rdata->tile_with, .start_y = 0,
			.end_y = scn->win->img_height,
			.buffer = (char *)scn->win->img.img,
			.scene = scn
		};

		if (indx == rdata->num_tiles - 1)
			thread_data[i].end_x = buffer->width;
	}
	pthread_create(&threads[i], NULL, render_thread, &thread_data[i]);
}
