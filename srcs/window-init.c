
#include "scene.h"
#include "window.h"
#include "vectors.h"
#include "memory-handler.h"

void init_window(t_scene *scn)
{
	t_window *win;

	win = (t_window *)xmalloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->img_width = 1024;
	win->aspect_ratio = (16 / 9);
	win->img_height = win->img_width / win->aspect_ratio; //575.9px
	if (win->img_height < 1)
		win->img_height = 1;
	win->viewport_height = 2.0;
	win->viewport_width = win->viewport_height * (win->img_height / win->img_width); //3.55556ratio
	vec3(&win->viewport_u, win->viewport_width, 0, 0);
	vec3(&win->viewport_v, 0, -win->viewport_height, 0);
	win->pixel_delta_u =  vec3_to_dbl(div_v3_dbl(&win->viewport_u, win->img_width));
	win->pixel_delta_v =  vec3_to_dbl(div_v3_dbl(&win->viewport_v, win->img_height));
	win->mlx_win = mlx_new_window(win->mlx, win->img_width, win->img_height, "MiniRT");
	win->img.img = mlx_new_image(win->mlx, win->img_width, win->img_height);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, &win->img.line_length,
								&win->img.endian);
	scn->win = win;
	listen_events();
}
