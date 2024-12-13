
#include "colours.h"
#include "maths.h"

/*
double	sum_rgb(t_color v1, t_color v2)
{
	double new;
	double r;
	double g;
	double b;


	r = (double)((v1.r + v2.r));
	g = (double)((v1.g + v2.g));
	b = (double)((v1.b + v2.b));
	new = r << 16.0 | g << 8.0 | b;
	return (new);
}*/

t_color mult_rgb_dbl(t_color rgb, double scale)
{
	t_color new;
	int r;
	int g;
	int b;
	
	r = rgb.r * scale;
	g = rgb.g * scale;
	b = rgb.b * scale;
	new.clr = (r << 16)	| (g << 8) | b;
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
/*
t_color color_scale(t_color rgb, double scale)
{
	t_color	new;
	double	r;
	double	g;
	double	b;
	t_interval inter;

	inter.min = 0;
	inter.max = 255;
	r = clamp(inter,((rgb.clr >> 16) & 0xFF) * scale);
	g = clamp(inter,((rgb.clr >> 8) & 0xFF) * scale);
	b = clamp(inter,((rgb.clr) & 0xFF) * scale);
	new.clr = (uint8_t)r << 16 | (uint8_t)g << 8 | (uint8_t)b;
	return (new);
}*/

t_color color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color c;

	c.clr = (uint8_t)(r) << 16 | (uint8_t)(g) << 8 | (uint8_t)(b);
	return (c);
}