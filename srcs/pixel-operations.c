
#include "vectors.h"
#include "maths.h"

/*
* @brief Returns the vector to a random point in the [-.5,-.5]-[+.5,+.5] unit square.
*
static t_vec3 random_square()
{
	return vec3((random_float() - 0.5), (random_float() - 0.5), 0);
}
*/

/*
* @brief
* pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v)
*/
t_vec3 get_pix_rand_pos(t_vec3 *pix00, t_vec3 *dlt_u, t_vec3 *dlt_v, t_ivec2 *pix_pos)
{
	t_vec3	pu;
	t_vec3	pv;
	t_vec3	delta;
	// t_vec3	offset;

	// offset = random_square();
	// printf("Pixel center offset[%f,%f,%f]\n", offset.x, offset.y, offset.z);
	pu = mult_v3_dbl(*dlt_u, (float)pix_pos->x); // + offset.x);
	pv = mult_v3_dbl(*dlt_v, (float)pix_pos->y); //+ offset.y);
	delta = sum_v3(*pix00, pu);
	return(sum_v3(delta, pv));
}

