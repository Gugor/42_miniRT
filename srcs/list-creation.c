/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list-creation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 13:45:07 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/27 18:59:09 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "lists.h"
#include "shapes.h"
#include "memory-handler.h"

t_lst	*new_lst_node(int indx, void *cnt, t_entid type)
{
	t_lst	*new;

	new = xmalloc(sizeof(t_lst));
	new->cnt = cnt;
	new->indx = indx;
	new->type = type;
	return (new);
}

t_lst	*find_lst_last(t_lst *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	add_node_to(t_lst **lst, void *content, t_entid type)
{
	t_lst	*new;
	t_lst	*last;

	last = NULL;
	last = find_lst_last(*lst);
	if (!lst || !content)
		return ;
	if (!*lst)
	{
		new = new_lst_node(0, content, type);
		new->prev = NULL;
		new->next = NULL;
		*lst = new;
	}
	else
	{
		last = find_lst_last(*lst);
		last->next = new_lst_node(last->indx + 1, content, type);
		last->next->prev = last;
		*lst = last;
	}
}