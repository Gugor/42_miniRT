

#ifndef MATHS_H
# define MATHS_H

# include <math.h>

# define PI 3.1415926535897932385

typedef struct s_interval
{
	double min;
	double max;
}	t_interval;

void init_limits(t_interval *inter, double min, double max);
double degrees_to_radians(double degrees);
#endif