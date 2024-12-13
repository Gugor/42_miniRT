
#include "scene.h"
#include "camera.h"
// #include "logger.h"
#include "window.h"
#include "vectors.h"
#include "memory-handler.h"

static void set_win_pivot(t_camera *camera, t_window *win)
{
	t_vec3 dir_flnght;
	t_vec3 half_vwp_u;
	t_vec3 half_vwp_v;
	t_vec3 rest1;
	t_vec3 rest2;

	printf("	=> Calc Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_v.z);
	half_vwp_u = div_v3_dbl(win->viewport_u, 2.0);
	printf("	=> Calc UCL Half Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_v.z);
	printf("	=> Calc Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	half_vwp_v = div_v3_dbl(win->viewport_v, 2.0);
	printf("	=> Calc UCL Half Viewport V[%f,%f,%f]\n", half_vwp_v.x, half_vwp_v.y, half_vwp_v.z);
	dir_flnght = vec3(0, 0, camera->focal_length);
	rest1 = rest_v3(camera->pos, dir_flnght);
	rest2 = rest_v3(rest1, half_vwp_u);
	win->viewport_pivot = rest_v3(rest2, half_vwp_v); 
	printf("	=> Upper Left Corener[%f,%f,%f]\n", win->viewport_pivot.x, win->viewport_pivot.y, win->viewport_pivot.z);
}

/**
 * @brief PX00 is the initial pixel in the top left part of the viewport. This
 * function initialize it with the window data.
 */
static void set_px00(t_window *win)
{
	t_vec3 init_pixel;
	init_pixel = sum_v3(win->pixel_delta_u, win->pixel_delta_v);
	init_pixel = mult_v3_dbl(init_pixel, 0.5);
	init_pixel = sum_v3(win->viewport_pivot, init_pixel);
	win->p00 = init_pixel;
}
static void init_viewport(t_scene *scn, t_window *win)
{
	printf("Initializing Viewport(%ix%i)...\n", (int)win->img_width, (int)win->img_height);
	win->viewport_height = 2.0;
	win->viewport_width = win->viewport_height * (double)win->img_width / (double)win->img_height; //3.55556ratio
	printf("	:: Viewporwidth: %f\n", win->viewport_width);
	win->viewport_u = vec3(win->viewport_width, 0, 0);
	win->viewport_v = vec3(0, -win->viewport_height, 0);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.x, win->viewport_v.z);
	win->pixel_delta_u =  div_v3_dbl(win->viewport_u, win->img_width);
	win->pixel_delta_v =  div_v3_dbl(win->viewport_v, win->img_height);
	set_win_pivot(&scn->camera, win);
	set_px00(win);
	// log_vwp_data(win);
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
	printf("Win Width: %i\n", win->img_width);
	printf("Win Height: %i\n", win->img_height);
	printf("Win Aspec ratio: %f\n", win->aspect_ratio);
	if (win->img_height < 1)
		win->img_height = 1;
	init_viewport(scn, win);
	win->mlx_win = mlx_new_window(win->mlx, win->img_width, win->img_height, "MiniRT");
	win->img.img = mlx_new_image(win->mlx, win->img_width, win->img_height);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, &win->img.line_length,
								&win->img.endian);
	scn->win = win;
	listen_events();
}
