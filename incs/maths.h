

#ifndef MATHS_H
# define MATHS_H

# include <math.h>
# include <stdbool.h>
# include "vectors.h"

# define PI 3.1415926535897932385

typedef struct s_interval
{
	double min;
	double max;
}	t_interval;

double		degrees_to_radians(double degrees);

void		init_limits(t_interval *inter, double min, double max);
bool		interval_contains(t_interval *inter, double p);
bool		interval_surrounds(t_interval *inter, double p);
double		interval_size(t_interval *inter);

void		universe(t_interval *inter);
void		empty(t_interval *inter);
double		clamp(t_interval *inter, double x) ;

double		random_double();
double		random_double_range(double min, double max);
t_vec3		random_v3();
t_vec3		random_range_v3(double min, double max);
t_vec3		random_unit_vector();
t_vec3		random_on_hemisphere(const t_vec3 normal);
#endif