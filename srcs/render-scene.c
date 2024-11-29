

#include "rendering.h"
#include "libft.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}

void render_scene(t_scene *scn)
{
	printf("=> Rendering Scene(%p)...\n", scn);
	char *win_size_ui;
	my_mlx_pixel_put(&scn->win->img, 100, 100, 0x00FF0000);
	//my_mlx_pixel_put(&scn->win->img, 6, 6, 0x00FF0000);
	//my_mlx_pixel_put(&scn->win->img, 7, 7, 0x00FF0000);
	win_size_ui = ft_strjoin(ft_itoa(scn->win->img_width), "x");
	win_size_ui = ft_strjoin(win_size_ui, ft_itoa(scn->win->img_height));
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 15, 0x00FF0000, "16/9");
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 30, 0x00FF0000, win_size_ui);
}