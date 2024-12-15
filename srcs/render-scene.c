

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
 *
void cast_ray(t_scene *scn)
{
	return ;
}
*/

/**
 * @brief 
 * Sky Blue: 20, 109, 252 White Sky: 247, 250, 255
 */
static void render_image(t_scene *scn, t_window *win)
{
	int			w;
	int			h;	
	int			samples;
	t_ivec2		pix_pos;
	t_ray		ray;
	t_color		new_color;
	t_color		prev_color;

	w = -1;
	h = -1;
	printf("	=> Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_v.z);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	printf("	=> Viewport Delta U[%f,%f,%f]\n", win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z);
	printf("	=> Viewport Delta V[%f,%f,%f]\n", win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	prev_color = color(0,0,0);
	while (++h < win->img_height)
	{
		while (++w < win->img_width)
		{
			pix_pos.x = w;
			pix_pos.y = h;
			new_color = color(0,0,0); 
			samples = -1;
			while (++samples < scn->camera.samples_per_pixel)
			{
				ray = get_ray(win, &scn->camera, &pix_pos);
				printf("Pos[%i,%i] ", h, w);
				if (w < 1)
					new_color = ray_color(&ray);
				else
					new_color = sum_rgb(ray_color(&ray), prev_color);
				prev_color = new_color;
			}
			new_color = mult_rgb_dbl(new_color, scn->camera.pixel_sample_scale);
			my_mlx_pixel_put(&win->img, w, h, new_color.clr);
			// my_mlx_pixel_put(&win->img, w, h, new_color.clr * scn->camera.pixel_sample_scale);
			// usleep(70000);
		}
		w = -1;
	}
}

void render_scene(t_scene *scn)
{
	printf("=> Rendering Scene(%p)...\n", scn);
	render_image(scn, scn->win);
	mlx_put_image_to_window(scn->win->mlx, scn->win->mlx_win, scn->win->img.img, 0, 0);
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 15, 0x00FF0000, "16/9");
	mlx_string_put(scn->win->mlx, scn->win->mlx_win, 5, 30, 0x00FF0000, "1920x1080");
}