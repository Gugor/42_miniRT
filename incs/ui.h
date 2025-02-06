/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 13:02:44 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/06 18:04:08 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef UI_H
# define UI_H

# include "lists.h"

# define W_pad 5
# define H_pad 15

typedef struct s_panel
{
	t_lst *items;


}	t_panel;

typedef struct s_txt_lable
{
	int	id;
	int level;
	char *label;
	char *cnt;


}	t_txt_label;

#endif