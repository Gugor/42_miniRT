/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarsa-s <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:04:13 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/01/20 16:04:38 by mmarsa-s         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lights.h"
#include "shape-maths.h"
#include "ray.h"
#include "colours.h"

static t_color	calculate_highlights()
{

}

static t_color	calculate_shadows()
{

}

void	calculate_lights(t_hit_data *hitd, t_lst *shapes)
{
	t_lst	*lights;
	t_light	*light;
	t_scene *scn;
	t_ray	*ray;
	t_interval	*lim;

	scn = get_scene();
	lights = scn->lights;
	init_limits(lim, 0.001, INFINITY);
	while (lights)
	{
		light = (t_light *)lights->cnt;
		*ray = init_ray(&hitd->hit, &light->pos);
		if (hit(ray, &lim, hitd))
			calculate_shadows();
		else
			calculate_highlights();
		lights = lights->next;
	}
}