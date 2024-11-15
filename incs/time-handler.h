/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time-handler.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:50:05 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 17:56:03 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TIME_HANDLER_H
#define TIME_HANDLER_H

int64_t get_current_time(char precision);
char *get_timestamp(void);
int64_t get_elapsed_time(int64_t start, char precision);

#endif
