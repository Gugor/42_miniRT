
#include "time.h"

/**
 * @brief It gets the time passed between two moments. You
 * can set the precision in seconds o microseconds.
*/
int64_t	get_elapsed_time(int64_t start, char precision)
{
	int64_t	end;

	end = get_current_time(precision);
	return (end - start);
}

/**
 * @brief It returns the current time with the prcision given seconds 
 * or microseconds.
 * @return `{time_t (int64_t)}`
*/
int64_t	get_current_time(char precision)
{
	struct timeval		tv;
	struct timezone		*tz;

	if (gettimeofday(&tv, &tz) < 0)
		return (124);
	if (precision == 's' || precision == 'S')
		return ((tv.tv_sec + (tv.tv_usec / 1000000L)));
	if (precision == 'm' || precision == 'M')
		return ((tv.tv_sec * 1000L) + (tv.tv_usec / 1000L));
	if (precision == 'u' || precision == 'U')
		return ((tv.tv_sec * 1000000L) + (tv.tv_usec));
	return (-1);
}