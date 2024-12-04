

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
	t_sphere sp;

	w = -1;
	h = -1;
	printf("	=> Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_v.z);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	printf("	=> Viewport Delta U[%f,%f,%f]\n", win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z);
	printf("	=> Viewport Delta V[%f,%f,%f]\n", win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	// sp = (t_sphere *)scn->shapes->next->cnt;
	vec3(&sp.pos, 0, 0, -0.5);
	sp.size = 0.2;
	(void)scn;
	while (++h < win->img_height)
	{
		while (++w < win->img_width)
		{
			indx[0] = w;
			indx[1] = h;
			pixel_center = get_pix_center(&win->p00, &win->pixel_delta_u, &win->pixel_delta_v, indx);
			printf("[%i,%i] - P00[%f,%f,%f]\n", w, h, pixel_center.x, pixel_center.y, pixel_center.z);
			ray_dir = rest_v3(&pixel_center, &scn->camera.center);
			printf("Cam pos[%f,%f,%f]\n", scn->camera.center.x, scn->camera.center.y, scn->camera.center.z);
			ray = init_ray((t_vec3 *)&scn->camera.center, &ray_dir);
			printf("Pos[%i,%i] ", h, w);
			color = ray_color(&ray);
			//printf("	::CLR RGB[%u,%u,%u][%i]\n", (color.clr >> 16) & 0xFF, (color.clr >> 8) & 0xFF , color.clr & 0xFF, color.clr);
			//color.clr = lerpRGB(ray.direction, scale_rgb(1.0, 1.0, 1.0), scale_rgb(0.5,0.7, 1.0));
			printf("	::CLR RGB[%u,%u,%u][%i]\n", (color.clr >> 16) & 0xFF, (color.clr >> 8) & 0xFF , color.clr & 0xFF, color.clr);
			my_mlx_pixel_put(&win->img, w, h, color.clr);
			// usleep(70000);
		}
		w = -1;
	}
}

void render_scene(t_scene *scn)
{
	printf("=> Rendering Scene(%p)...\n", scn);
	// char *win_size_ui;
	render_image(scn, scn->win);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
	//win_size_ui = ft_strjoin(ft_itoa(scn->win->img_width), "x");
	//win_size_ui = ft_strjoin(win_size_ui, ft_itoa(scn->win->img_height));
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 15, 0x00FF0000, "16/9");
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 30, 0x00FF0000, "1920x1080");
}