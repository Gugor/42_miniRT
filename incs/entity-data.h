/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity-data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:36 by hmontoya          #+#    #+#             */
/*   Updated: 2025/02/02 23:55:55 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_DATA_H
# define ENTITY_DATA_H

# define SHAPE_TYPE_OFFSET 3

typedef enum e_entid
{
	AMBIENT,
	LIGHT,
	CAMERA,
	PLANE,
	SPHERE,
	CYLINDER,
	TORUS,
	EOS
}	t_entid;

#endif