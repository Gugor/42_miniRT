/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freesimple.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 15:22:51 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/21 19:10:25 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief It frees the memory allocated for a pointer
 * @param ptr `{void *}` It a pointer to the space of memory to be freed.
 */
void	memfree(void **ptr)
{
	if (ptr && *ptr)
		free(*ptr);
	*ptr = NULL;
	return ;
}
