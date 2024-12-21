
#ifndef TIME_H
# define TIME_H

# include <sys/time.h>
# include <stdint.h>


int64_t	get_current_time(char precision);
int64_t	get_elapsed_time(int64_t start, char precision);

#endif