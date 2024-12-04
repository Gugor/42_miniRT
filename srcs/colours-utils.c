

#include "vectors.h"
#include "colours.h"

/**
 * @brief
 */
t_color set_color(uint8_t r, uint8_t g, uint8_t b)
{
	t_color c;

	c.r = r;
	c.g = g;
	c.b = b;
	return (c);
}

/**
 * @brief It check if the given vec3 value are in range.
*/
int	in_range_rgb(t_color val, uint8_t  min, uint8_t max)
{
	if (val.r < min || val.r > max)
		return (0);
	if (val.g < min || val.g > max)
		return (0);
	if (val.b < min || val.b > max)
		return (0);
	return (1);
}

/**
 * @brief It converst from vec3 to t_color
*/
t_color	vec3_to_rgb(t_vec3 *v3)
{
	t_color	rgb;

	rgb.clr = 0;
	rgb.r = v3->x;
	rgb.g = v3->y;
	rgb.b = v3->z;
	return (rgb);
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

/**
 * Maps the a dimention into another by scaling it.
 *  
*/
int lerpRGB(double pos, t_color from, t_color to)
{
	double		a;
	t_ncolor	f;
	t_ncolor	t;
	t_color 	i;

	i.clr = 0;
	f.r = (from.clr >> 16) & 0xFF; 
	f.g = (from.clr >> 8) & 0xFF; 
	f.b = (from.clr) & 0xFF; 
	// printf("		:: [%f]From RGB[%u,%u,%u]\n",pos, f.r, f.g , f.b);
	t.r = (to.clr >> 16) & 0xFF; 
	t.g = (to.clr >> 8) & 0xFF; 
	t.b = (to.clr) & 0xFF; 
	// printf("		:: [%f]To RGB[%u,%u,%u]\n",pos, t.r, t.g , t.b);
	a = 0.5 * pos + 1.0; 
	// printf("			-> I[%f]\n", a);
	i.clr |= (uint8_t)((1.0 - a) * f.r + a * t.r) << 16;
	// printf("			-> R[%d][%u]\n", (i.clr >> 16) & 0xFF, (uint8_t)((1.0 - a) * f.r + a * t.r));
	i.clr |= (uint8_t)((1.0 - a) * f.g + a * t.g) << 8;
	// printf("			-> G[%d][%u]\n", (i.clr >> 8) & 0xFF, (uint8_t)((1.0 - a) * f.g + a * t.g));
	i.clr |= (uint8_t)((1.0 - a) * f.b + a * t.b);
	// printf("			-> B[%d][%u]\n", i.clr & 0xFF, (uint8_t)((1.0 - a) * f.b + a * t.b));
	// printf("		::->[%f]Interpolated RGB[%u,%u,%u][%i]\n",a, (i.clr >> 16) & 0xFF, (i.clr >> 8) & 0xFF , i.clr & 0xFF, i.clr);
	return(i.clr);
}
