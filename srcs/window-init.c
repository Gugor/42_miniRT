
#include "scene.h"
#include "window.h"
#include "vectors.h"
#include "memory-handler.h"

static void set_win_pivot(t_scene *scn, t_window *win)
{
	t_vec3 dir_flnght;
	t_vec3 half_vwp_u;
	t_vec3 half_vwp_v;
	t_vec3 rest1;
	t_vec3 rest2;

	vec3(&dir_flnght, 0, 0, scn->camera.focal_length);
	half_vwp_u = div_v3_dbl(&scn->win->viewport_u, 2.0);
	half_vwp_v = div_v3_dbl(&scn->win->viewport_v, 2.0);
	rest1 = rest_v3(&dir_flnght, &half_vwp_u);
	rest2 = rest_v3(&rest1, &half_vwp_v);
	win->viewport_pivot = rest_v3(&scn->camera.center, &rest2); 
}

static void init_viewport(t_scene *scn, t_window *win)
{
	win->viewport_height = 2.0;
	win->viewport_width = win->viewport_height * (win->img_height / win->img_width); //3.55556ratio
	printf("	:: Viewpoerwidth: %f\n", win->viewport_height * (win->img_height / win->img_width));
	vec3(&win->viewport_u, win->viewport_width, 0, 0);
	vec3(&win->viewport_v, 0, -win->viewport_height, 0);
	win->pixel_delta_u =  vec3_to_dbl(div_v3_dbl(&win->viewport_u, win->img_width));
	win->pixel_delta_v =  vec3_to_dbl(div_v3_dbl(&win->viewport_v, win->img_height));
	set_win_pivot(scn, scn->win);
	printf("=> Viewport data:\n");
	printf("	:: Resolution: %fx%f\n", win->viewport_width, win->viewport_height);
	printf("	:: UV: U[%f,%f, %f] | V[%f,%f, %f]\n",
			win->viewport_u.x, win->viewport_u.y, win->viewport_u.z,
			win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);	
	printf("	:: Delta UV: U[%f] | V[%f]\n", win->pixel_delta_u, win->pixel_delta_u);
	printf("	:: Upper Left Pivot: [%f,%f,%f]\n", win->viewport_pivot.x, win->viewport_pivot.y, win->viewport_pivot.z);
}

void init_window(t_scene *scn)
{
	t_window *win;

	win = (t_window *)xmalloc(sizeof(t_window));
	win->mlx = mlx_init();
	win->img_width = 1920;
	win->aspect_ratio = 16.0 / 9.0;
	win->img_height = win->img_width / win->aspect_ratio; //575.9px
	printf("=> Window data\n");
	printf("Win Width: %f\n", win->img_width);
	printf("Win Height: %f\n", win->img_height);
	printf("Win Aspec ratio: %f\n", win->aspect_ratio);
	if (win->img_height < 1)
		win->img_height = 1;
	init_viewport(scn, scn->win);
	win->mlx_win = mlx_new_window(win->mlx, win->img_width, win->img_height, "MiniRT");
	win->img.img = mlx_new_image(win->mlx, win->img_width, win->img_height);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, &win->img.line_length,
								&win->img.endian);
	scn->win = win;
	listen_events();
}
