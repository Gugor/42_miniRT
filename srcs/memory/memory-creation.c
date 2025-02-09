/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory-creation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 13:35:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/27 14:16:33 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include "memory-handler.h"

void	*xmalloc(int size)
{
	void	*mem;

	mem = malloc(size);
	if (!mem)
	{
		clear_scene();
		perror("Error: ");
		exit(ENOMEM);
	}
	return (mem);
}
