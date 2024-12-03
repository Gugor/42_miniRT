

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

	rgb.r = v3->x;
	rgb.g = v3->y;
	rgb.b = v3->z;
	return (rgb);
}

/**
 * Maps the a dimention into another by scaling it.
 *  
*/
  double lerpRGB(double unscaled, double min_limit, double max_limit, double min, double max)
  {
	  //int min;

	  //min = 0;
      return((max_limit - min_limit) * (unscaled - min) / (max - min) + min_limit);
  }

  t_ucolor	color_to_mlx(t_color *c)
  {
		t_ucolor clr;

		clr.clr = (int)(c->r << 16 | c->g << 8 | c->b);
		return (clr);
  }