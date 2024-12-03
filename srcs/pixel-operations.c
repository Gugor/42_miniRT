
#include "vectors.h"

/*
* @brief
* pixel00_loc + (i * pixel_delta_u) + (j * pixel_delta_v)
*/
t_vec3 get_pix_center(t_vec3 *pix00, t_vec3 *dlt_u, t_vec3 *dlt_v, int indx[2])
{
	t_vec3 pu;
	t_vec3 pv;
	t_vec3 res;
	pu = mult_v3_dbl(dlt_u, (double)indx[0]);
	pv = mult_v3_dbl(dlt_v, (double)indx[1]);
	res = sum_v3(pix00, &pu);
	return(sum_v3(&res, &pv));
}
