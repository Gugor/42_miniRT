
#include "maths.h"
#include "vectors.h"

void universe(t_interval *inter)
{
	inter->min = -INFINITY;
	inter->max = INFINITY;	
}

void empty(t_interval *inter)
{
	inter->min = INFINITY;
	inter->max = -INFINITY;	
}

double clamp(t_interval *inter, double x) 
{
	if (x < inter->min)
		return inter->min;
	if (x > inter->max)
		return inter->max;
	return x;
}