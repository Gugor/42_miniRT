

#ifndef MATHS_H
# define MATHS_H

# include <math.h>
# include <stdbool.h>
# include "vectors.h"

# define PI 3.1415926535897932385

typedef struct s_interval
{
	float min;
	float max;
}	t_interval;

float		degrees_to_radians(float degrees);

void		init_limits(t_interval *inter, float min, float max);
bool		interval_contains(t_interval *inter, float p);
bool		interval_surroundss(t_interval *inter, float p);
float		interval_size(t_interval *inter);

void		universe(t_interval *inter);
void		empty(t_interval *inter);
float		clamp(t_interval *inter, float x) ;

float		random_float();
float		random_float_range(float min, float max);
t_vec3		random_v3();
t_vec3		random_range_v3(float min, float max);
t_vec3		random_unit_vector();
t_vec3		random_on_hemisphere(const t_vec3 normal);
#endif