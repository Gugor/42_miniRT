/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list-iteration.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:29:57 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 14:34:21 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lists.h"

static void	*go_lst_up(t_lst *lst, int indx)
{
	while (lst && lst->indx > indx)
		lst = lst->prev;
	return (lst);
}

static void	*go_lst_down(t_lst *lst, int indx)
{
	while (lst && lst->indx < indx)
		lst = lst->next;
	return (lst);
}

void	*get_node_at(t_lst *lst, int indx)
{
	if (indx >= lst->length)
		return (NULL);
	if (lst->indx > indx)
		return (go_lst_down(lst, indx));
	else
		return (go_lst_up(lst, indx));
}

