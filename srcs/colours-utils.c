

#include "colours.h"

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
 * Maps the a dimention into another by scaling it.
 *  
*/
  double lerpRGB(double unscaled, double min_limit, double max_limit, double min, double max)
  {
	  //int min;

	  //min = 0;
      return((max_limit - min_limit) * (unscaled - min) / (max - min) + min_limit);
  }