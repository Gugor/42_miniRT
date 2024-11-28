/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-handler.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 19:08:19 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/28 19:23:31 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEMORY_HANDLER_H
# define MEMORY_HANDLER_H

# include <errno.h>
# include "lists.h"
# include "mlx.h"

void	*xmalloc(int size);
void	clear_list(t_lst *lst, void (*del)(t_lst **node, int mode));
void	clear_scene(void);

#endif
