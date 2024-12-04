/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-free.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:36:07 by hmontoya          #+#    #+#             */
/*   Updated: 2024/12/04 14:45:42 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "memory-handler.h"
#include "scene.h"
#include "libft.h"

/**
 * @brief It deletes a node form a `t_lst`. It needs the node
 * to be at the beginning or end of the list.
 * @returns `{void}`
*/
static void	delete_node(t_lst **node, int mode)
{
	if (!node || !*node)
		return ;
	if (mode)
	{
		if ((*node)->next)
			(*node)->next->prev = NULL;
	}
	else
	{
		if ((*node)->prev)
			(*node)->prev->next = NULL;
	}
	if ((*node)->cnt)
		memfree((void **)&(*node)->cnt);
	memfree((void **)node);
	*node = NULL;
}

/**
 * @brief This function free from memory a list of `t_lst` elements.
 * It uses a callbac function as a way to remove those elements. See 
 * `delete_node()`.
 * @returns `{void}`
*/
void	clear_list(t_lst *lst, void (*del)(t_lst **node, int mode))
{
	t_lst	*head;

	head = NULL;
	while (lst)
	{
		head = lst->next;
		del(&lst, 1);
		lst = head;
	}
}

/**
 * @brief The scene data is allocated in stack but some of its elements
 * are heap allocated. This function cleans from memory those elements.
 * This function use `get_scene()` to retrieve the current scene.
 * @returns `{void}`
*/
void	clear_scene(void)
{
	t_scene	*scene;

	scene = get_scene();
	if (scene->lights)
		clear_list(scene->lights, &delete_node);
	if (scene->shapes)
		clear_list(scene->shapes, &delete_node);
	// if (scene->win && scene->win->img.img)
	// 	mlx_destroy_image(scene->win->mlx, (void *)&scene->win->img);
	if (scene->win && scene->win->mlx && scene->win->mlx_win)
		mlx_destroy_window(scene->win->mlx, scene->win->mlx_win);
	if (scene->win)
		memfree((void **)&scene->win);
}
