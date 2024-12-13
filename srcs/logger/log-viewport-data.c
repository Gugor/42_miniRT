

#include "window.h"
#include "libft.h"

void log_vwp_data(t_window *win)
{
	printf("=> Viewport data:\n");
	printf("	:: Resolution: %fx%f\n", win->viewport_width, win->viewport_height);
	printf("	:: UV: U[%f,%f, %f] | V[%f,%f, %f]\n",
			win->viewport_u.x, win->viewport_u.y, win->viewport_u.z,
			win->viewport_v.x, win->viewport_v.y, win->viewport_v.z);	
	printf("	:: Delta UV: U[%f, %f, %f] | V[%f, %f, %f]\n",
			win->pixel_delta_u.x, win->pixel_delta_u.y, win->pixel_delta_u.z,
			win->pixel_delta_v.x, win->pixel_delta_v.y, win->pixel_delta_v.z);
	printf("	:: Upper Left Pivot: [%f,%f,%f]\n", win->viewport_pivot.x, win->viewport_pivot.y, win->viewport_pivot.z);
	printf("	:: 00 Pixel: [%f,%f,%f]\n", win->p00.x, win->p00.y, win->p00.z);
}