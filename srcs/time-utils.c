/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time-utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 17:53:36 by hmontoya          #+#    #+#             */
/*   Updated: 2024/11/15 17:59:57 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time-handler.h"

int64_t get_current_time(char precision)
{     
        struct timeval          tv;
        struct timezone         *tz;
      
        if (gettimeofday(&tv, &tz) < 0)
                return (errno);
        if (precision == 's' || precision == 'S')
                return ((tv.tv_sec + (tv.tv_usec / 1000000L)));
        if (precision == 'm' || precision == 'M')
                return ((tv.tv_sec * 1000000L) + tv.tv_usec);
        if (precision == 'c' || precision == 'C')
                return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
        return (-1);
}     

/**
* @brief it creates a `char *` string with the current timestamp.
* @returns `{char *}`
* `char * in case could create a timestamp`
* `NULL in case of an error`
*/
char *get_timestamp(void)
{
	int64_t ctime;	
	
	return (get_current_time("u"))
}

/**   
 * @brief It gets the time passed between two moments. You
 * can set the precision in seconds o microseconds.
*/    
int64_t get_elapsed_time(int64_t start, char precision)
{     
        int64_t end;
      
        end = get_current_time(precision);
        return (end - start);
}     


