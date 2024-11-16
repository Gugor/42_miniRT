/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 17:52:34 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/14 17:53:36 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
#define FILE_H

int open_rt(char *rt_path)
{
	t_scene	*scene;
	int	fd;

	scene = get_scene();
	if((fd = open(rt_path, O_RDONLY)) == -1) 	
	{
		err_rt_file_not_open(errno);
		exit(ERR_FILE_NO_OPEN);
	}
}


#endif;
