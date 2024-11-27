/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   entity-data.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 18:27:36 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/27 15:05:17 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITY_DATA_H
# define ENTITY_DATA_H

typedef enum e_entid
{
	AMBIENT,
	LIGHT,
	CAMERA,
	PLANE,
	SPHERE,
	CYLINDER,
	OTHER,
	EOS
}	t_entid;

#endif