/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 16:16:47 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/13 00:48:31 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERING_H
# define RENDERING_H

# include <pthread.h>
# include "vectors.h"
# include "ray.h"

# ifndef MULTITHREADING
#  define MULTITHREADING	1
# endif

typedef struct s_scene t_scene;

typedef struct s_rm_tile
{
	int				start_x;
	int				end_x;
	int				start_y;
	int				end_y;
	char			*buffer;
	t_ray			ray;
	t_color			new_color;
	t_scene			*scn;
	t_ivec2			px_pos;
	pthread_mutex_t	*rmut;
}	t_rm_tile;

typedef struct s_rdata
{
	int				num_tiles;
	int				tl_width;
	pthread_t		*thrds;
	t_rm_tile		*tls;
	pthread_mutex_t	rmut;
	int64_t				start_render_tme;
	int				indx;
}	t_rdata;

void		render_scene(t_scene *scene);
int			render_image(void *data);
t_vec3		get_pix_rand_pos(t_vec3 *pix00, t_vec3 *dlt_u,
				t_vec3 *dlt_v, t_ivec2 *pix_pos);
int			render_multithreaded(void *data);
int			get_num_threads(t_rdata *rd);
void		*render_thread(void *arg);
#endif