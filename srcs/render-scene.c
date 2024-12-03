

#include "rendering.h"
#include "ray.h"
#include "libft.h"
#include "shapes.h"
#include "shape-maths.h"

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bpp / 8));
	*(unsigned int*)dst = color;
}
/**
 * @brief 
 * Sky Blue: 20, 109, 252 White Sky: 247, 250, 255
 */
static void render_image(t_scene *scn, t_window *win)
{
	int		w;
	int		h;	
	int		indx[2];
	t_vec3	pixel_center;
	t_vec3	ray_dir;
	t_ray	ray;
	t_color color;
	t_ucolor uclr;
	t_sphere sp;

	w = -1;
	h = -1;
	printf("	=> Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_v.z);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	printf("	=> Viewport Delta U[%f,%f,%f]\n", win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z);
	printf("	=> Viewport Delta V[%f,%f,%f]\n", win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	// sp = (t_sphere *)scn->shapes->next->cnt;
	vec3(&sp.pos, 0, 0, -1);
	sp.size = 0.5;
	while (++h < win->img_height)
	{
		while (++w < win->img_width)
		{
			indx[0] = w;
			indx[1] = h;
			pixel_center = get_pix_center(&win->p00, &win->pixel_delta_u, &win->pixel_delta_v, indx);
			ray_dir = rest_v3(&pixel_center, &scn->camera.center);
			ray = init_ray((t_vec3 *)&scn->camera.center, &ray_dir);
			color = ray_color(&ray);
			uclr = color_to_mlx(&color);
			if (in_sphere((t_vec3 *)&sp.pos, sp.size, &ray) >= 0)
				my_mlx_pixel_put(&win->img, w, h, (255<< 16));
			else
				my_mlx_pixel_put(&win->img, w, h, uclr.clr);
			// usleep(70000);
		}
		w = -1;
	}
}

void render_scene(t_scene *scn)
{
	printf("=> Rendering Scene(%p)...\n", scn);
	char *win_size_ui;
	render_image(scn, scn->win);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
	win_size_ui = ft_strjoin(ft_itoa(scn->win->img_width), "x");
	win_size_ui = ft_strjoin(win_size_ui, ft_itoa(scn->win->img_height));
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 15, 0x00FF0000, "16/9");
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 30, 0x00FF0000, win_size_ui);
}