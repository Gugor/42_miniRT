/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logger.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:54:48 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 19:24:12 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGS_H
#define LOGS_H

# include "mrt-math.h"
# include "shapes.h"
# include <sys/time.h>
# include <fcntl.h>

typedef struct s_logger t_logger;

typedef struct s_logger
{
	int	fd;
	char	*filename;
	int	status;
	void	(*start)(t_logger *log);
	void	(*end)(t_logger *log);
} t_logger;

# ifndef LOG_FILE
#  define LOG_FILE "log.log"
# endif

void		logger(const char *msg, int newline);
void		log_vec3(const t_vec3 *vec, int newline);
void		log_doub(const double *doub, int newline);
void 		log_plane(const t_plane *plane, int newline);
void 		log_sphere(const t_sphere *sphere, int newline);
void 		log_cylind(const t_cylinder *cylinder, int newline);

int		logger_storage(t_logger *log);
int		init_logger(t_logger *log);
void		start_logger(t_logger *log);
void		end_logger(t_logger *log);
int		create_log_file(void);

#endif
