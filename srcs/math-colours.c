
#include "colours.h"

t_color		sum_rgb(t_color v1, t_color v2)
{
	t_color new;
	new.clr = (uint8_t)(v1.r + v2.r) << 16 | (uint8_t)(v1.g + v2.g) << 8
		| (uint8_t)(v1.b + v2.b);
	return (new);
}

/**
 * @brief This function scales a color with the given params.
 * RGB chanels are scalars numbers between 0 and 1. You need to see
 * this values as the percentage this channel is going to be activated.
 * 0 is 0 and 1.0 is 255.
 */
t_color scale_rgb(double r, double g, double b)
{
	t_color c;

	c.clr = (uint8_t)(255.999 * r) << 16 | (uint8_t)(255.999 * g) << 8 | (uint8_t)(255.999 * b);
	printf("Scale RGB[%u,%u,%u][%i]\n", (c.clr >> 16) & 0xFF, (c.clr >> 8) & 0xFF , c.clr & 0xFF, c.clr);
	return (c);
}

t_color mult_rgb_dbl(t_color rgb, double scale)
{
	t_color	new;
	double	r;
	double	g;
	double	b;

	r = ((rgb.clr >> 16) & 0xFF) * scale;
	g = ((rgb.clr >> 8) & 0xFF) * scale;
	b = ((rgb.clr) & 0xFF) * scale;
	new.clr = (uint8_t)r << 16 | (uint8_t)g << 8 | (uint8_t)b;
	return (new);
}