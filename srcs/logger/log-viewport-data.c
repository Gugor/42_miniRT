/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log-viewport-data.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 12:59:46 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/11 13:28:24 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "window.h"
#include "libft.h"

void	log_vwp_data(t_window *win)
{
	printf("=> Viewport data:\n");
	printf("	:: Resolution: %fx%f\n", win->viewport_width,
		win->viewport_height);
	printf("	:: UV: U[%f,%f, %f] | V[%f,%f, %f]\n",
		win->viewport_u.x, win->viewport_u.y, win->viewport_u.z,
		win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);
	printf("	:: Delta UV: U[%f, %f, %f] | V[%f, %f, %f]\n",
		win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z,
		win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	printf("	:: Upper Left Pivot: [%f,%f,%f]\n", win->viewport_pivot.x,
		win->viewport_pivot.y, win->viewport_pivot.z);
	printf("	:: 00 Pixel: [%f,%f,%f]\n", win->p00.x, win->p00.y, win->p00.z);
}

void	log_render_time(int elapsed)
{
	printf("Image rendered[%dms][%ds][%d:%dmins]\n", elapsed,
		(int)(elapsed * 0.001), (int)((elapsed * 0.001) / 60),
		(int)(elapsed * 0.001) - (int)(60 * (int)((elapsed * 0.001) / 60)));
}

void	log_create_light(t_light *lght)
{
	printf("=> Created Light:  \n");
	printf("	Pos: [%f,%f,%f]\n", lght->pos.x, lght->pos.y, lght->pos.z);
	printf("	BRGTNSS: %f\n", lght->brghtnss);
	printf("	RGB: [%hhu,%hhu,%hhu]\n", lght->rgb.r,
		lght->rgb.g, lght->rgb.b);
}
