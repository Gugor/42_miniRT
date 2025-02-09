/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:02:44 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/09 21:11:18 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UI_H
# define UI_H

# include "lists.h"

# define W_pad 5
# define H_pad 10
# define ITEM_HEIGHT 5

# define MAX_BUFFER 200

void		show_camera_movement_panel(t_scene *cam);
void		show_shades_mode_panel(t_scene *scn);
int			render_gui(void *data);


#endif