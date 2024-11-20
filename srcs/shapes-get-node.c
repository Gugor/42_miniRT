/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shapes-get-node.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 19:29:57 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 20:23:42 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"
#include "shapes.h"
//get_last_shape();
t_shape_lst	*new_sp_lst_node(int indx, void *shape, t_entid type)
{
	t_shape_lst	*new;

	new = (t_shape_lst *)malloc(sizeof(t_shape_lst));
	if (!new)
	{
		//call xmalloc();
	}
	new->indx = indx;
	new->type = type;
}

void add_shape_to(t_shape_lst *lst, void *shape, t_entid type)
{
	t_shape_lst *new;

	if (lst->last)
	{
		lst->last->next = new_sp_lst_node(lst->length, shape, type);  
		update_sp_lst_node(lst->last->next, lst->first, lst->last);
	}
	else
	{
		new = new_sp_lst_node(0, shape, type);
		update_sp_lst_node();
	}
}
static void	*go_shp_lst_up(t_shape_lst *lst, int indx)
{
	while (lst && lst->indx > indx)
		lst = lst->prev;
	return (lst);
}

static void	*go_shp_lst_down(t_shape_lst *lst, int indx)
{
	while (lst && lst->indx < indx)
		lst = lst->next;
	return (lst);
}

void	*get_shape_at(t_shape_lst *shps, int indx)
{
	void	*node;

	if (indx >= shps->length)
		return (NULL);
	node = NULL;
	if (shps->indx > indx)
		return (go_shlst_up(shps, indx));
	else
		return (go_shlst_up(shps, indx));
}