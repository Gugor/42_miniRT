

#include "rendering.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void render_scene(t_scene *scn)
{
	printf("=> Rendering Scene(%p)...\n", scn);
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 10, 10, 0, "MiniRT");
	my_mlx_pixel_put(&scn->win->img, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
}