
#include "colours.h"

t_color		sum_rgb(t_color *v1, t_color *v2)
{
	t_color new;
	new.clr = (uint8_t)(v1->r + v2->r) << 16 | (uint8_t)(v1->g + v2->g) << 8
		| (uint8_t)(v1->b + v2->b);
	return (new);
}