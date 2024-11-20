/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesimple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:22:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/20 15:22:55 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief It frees the memory allocated for a pointer
 * @param ptr `{void *}` It a pointer to the space of memory to be freed.
 */
void	free_simple(void **ptr)
{
	if (ptr && *ptr)
		free(*ptr);
	*ptr = NULL;
	return ;
}
