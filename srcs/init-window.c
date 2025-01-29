/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init-window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 14:46:31 by hmontoya          #+#    #+#             */
/*   Updated: 2025/01/23 17:07:17 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "camera.h"
// #include "logger.h"
#include "window.h"
#include "vectors.h"
#include "memory-handler.h"

/*
* @brief It sets the location of the camera in the screen.
*/
static void	set_win_pivot(t_camera *camera, t_window *win)
{
	t_vec3	dir_flnght;
	t_vec3	half_vwp_u;
	t_vec3	half_vwp_v;
	t_vec3	focl;
	t_vec3	foc_x_plane;

	printf("	=> Calc Viewport U[%f,%f,%f]\n", win->viewport_u.x,
		win->viewport_u.y, win->viewport_u.z);
	half_vwp_u = div_v3_dbl(win->viewport_u, 2.0);
	printf("	=> Calc UCL Half Viewport U[%f,%f,%f]\n",
		half_vwp_u.x, half_vwp_u.y, half_vwp_u.z);
	printf("	=> Calc Viewport V[%f,%f,%f]\n", win->viewport_v.x,
		win->viewport_v.y, win->viewport_v.z);
	half_vwp_v = div_v3_dbl(win->viewport_v, 2.0);
	printf("	=> Calc UCL Half Viewport V[%f,%f,%f]\n",
		half_vwp_v.x, half_vwp_v.y, half_vwp_v.z);
	// dir_flnght = vec3(0, 0, camera->focal_length);
	dir_flnght = scale_v3(camera->fordwards, camera->foc_dist);
	focl = sub_v3(camera->center, dir_flnght);
	foc_x_plane = sub_v3(focl, half_vwp_u);
	win->viewport_pivot = sub_v3(foc_x_plane, half_vwp_v);
	printf("	=> Upper Left Corner[%f,%f,%f]\n",
		win->viewport_pivot.x, win->viewport_pivot.y, win->viewport_pivot.z);
}

/**
 * @brief PX00 is the initial pixel in the top left part of the viewport. This
 * function initialize it with the window data.
 */
static void	set_px00(t_window *win)
{
	t_vec3	init_pixel;
	t_vec3	pix_size;
	t_vec3	pix_center;

	pix_size = sum_v3(win->pixel_delta_u, win->pixel_delta_v);
	pix_center = scale_v3(pix_size, 0.5);
	init_pixel = sum_v3(win->viewport_pivot, pix_center);
	win->p00 = init_pixel;
}

/**
 * @brief It set the viewport dimensions according to the left handed rule
 * system.
 * x+ to the right
 * y+ up
 * z+ front
 */
static void	init_viewport(t_scene *scn, t_window *win)
{
	printf("Initializing Viewport(%ix%i)(vfov[%f])...\n", (int)win->img_width, (int)win->img_height, scn->camera.fovV);
	win->viewport_height = 2.0 * scn->camera.h * scn->camera.foc_dist;
	win->viewport_width = win->viewport_height * ((double)win->img_width / (double)win->img_height); //3.55556ratio
	printf("	:: Viewporwidth: %f\n", win->viewport_width);
	printf("	:: Viewporheight: %f\n", win->viewport_height);
	win->viewport_u = scale_v3(scn->camera.u, win->viewport_width);//vec3(win->viewport_width, 0, 0);
	// win->viewport_v = scale_v3(scale_v3(scn->camera.v, -1), win->viewport_height);//vec3(0, -win->viewport_height, 0);
	win->viewport_v = scale_v3(scn->camera.v, -win->viewport_height);//vec3(0, -win->viewport_height, 0);
	// win->viewport_u = vec3(win->viewport_width, 0, 0);
	// win->viewport_v = vec3(0, -win->viewport_height, 0);
	printf("	=> Viewport U[%f,%f,%f]\n", win->viewport_u.x, win->viewport_u.y, win->viewport_u.z);
	printf("	=> Viewport V[%f,%f,%f]\n", win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	win->pixel_delta_u =  div_v3_dbl(win->viewport_u, win->img_width);
	win->pixel_delta_v =  div_v3_dbl(win->viewport_v, win->img_height);
	printf("	=> Pixel delta U[%f,%f,%f]\n", win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z);
	printf("	=> Pixel delta V[%f,%f,%f]\n", win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	set_win_pivot(&scn->camera, win);
	set_px00(win);
}

void init_window(t_scene *scn)
{
	t_window *win;

	win = (t_window *)xmalloc(sizeof(t_window));
	scn->win = win;
	win->mlx = mlx_init();
	win->img_width = 1080;
	win->aspect_ratio = 16.0 / 9.0;
	win->img_height = win->img_width / win->aspect_ratio; //575.9px
	printf("=> Window data\n");
	printf("Win Width: %i\n", win->img_width);
	printf("Win Height: %i\n", win->img_height);
	printf("Win Aspec ratio: %f\n", win->aspect_ratio);
	if (win->img_height < 1)
		win->img_height = 1;
	init_camera(&scn->camera);
	init_viewport(scn, win);
	win->mlx_win = mlx_new_window(win->mlx, win->img_width, win->img_height, "MiniRT");
	win->img.img = mlx_new_image(win->mlx, win->img_width, win->img_height);
	win->img.addr = mlx_get_data_addr(win->img.img, &win->img.bpp, &win->img.line_length,
								&win->img.endian);
	listen_events();
}


/**
* @brief It stores statically the scene object, te be retrieved when needed.
* @param `{t_scene *}` a pointer to the scene data strcuture.
* @returns `{t_scene *}`
* `a scene`
* `NULL if it no scene has been stored`
* NOTE: this function does not allocates memory it just stores a pointer to
* memory.
* so be aware where this memory is allocate and take messures in case you need
* to manually free it.
* Currently, the idea is store the scene in the stack, but we never know if 
* this would change.
*/
t_scene	*scene_storage(t_scene *storage)
{
	static t_scene	*scene = NULL;	

	if (!storage && !scene)
		return (NULL);
	if (storage)
		scene = storage;
	return (scene);
}
