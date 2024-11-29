/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:59:32 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/29 17:29:50 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
* Code related with minilibx. Open/Create and Close window, and rendering image
*/
#ifndef WINDOW_H
# define WINDOW_H

# include "scene.h"
# include "mlx.h"

typedef struct	s_img {
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_window
{
	double				aspect_ratio;
	double				pixel_delta_u;
	double				pixel_delta_v;
	double				viewport_height;
	double				viewport_width;
	int					img_width;
	int					img_height;
	void				*mlx;
	void				*mlx_win;
	t_img				img;
	t_vec3				viewport_u;
	t_vec3				viewport_v;

}	t_window;


typedef struct s_scene t_scene;

void	init_window(t_scene *scn);

#endif
