
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