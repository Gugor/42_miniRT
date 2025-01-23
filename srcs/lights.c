/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lights.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmontoya <hmontoya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 16:04:13 by mmarsa-s          #+#    #+#             */
/*   Updated: 2025/01/22 13:13:18 by hmontoya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "lights.h"
#include "shape-maths.h"
#include "colours.h"

static void	calculate_shadows(t_ray *ray, t_hit_data *hitd, t_light *light)
{
	double	dist;
	double	intensity;
	double	diffuse_factor; // Factor difuso basado en la normal y la luz
	t_vec3	quad;
	t_vec3	light_dir; // Dirección hacia la luz desde el punto de incidencia

	// Coeficientes de atenuación
	quad.x = 1;
	quad.y = 0.1;
	quad.z = 0.01;

	// Calcular distancia de la luz al punto
	dist = ray->length;

	// Calcular dirección hacia la luz (y normalizarla)
	light_dir = normalize_v3(sub_v3(light->pos, hitd->hit));
	// light_dir = sub_v3(hitd->hit, light->pos);

	// Producto escalar entre la normal de la superficie y la dirección de la luz
	diffuse_factor = dot(&hitd->out_normal, &light_dir);

	// Asegurarse de que el factor difuso no sea negativo
	if (diffuse_factor < 0)
		diffuse_factor = 0;

	// Calcular la atenuación de la luz basada en la distancia
	intensity = 1 / (quad.x + (quad.y * dist) + (quad.z * dist * dist)); 

	// Combinar la intensidad difusa con la luz de la fuente
	hitd->rgb = sum_rgb(
		sum_rgb(hitd->orgb, scale_color(hitd->orgb, 1 - intensity)), // Atenuación de la luz ambiental
		// hitd->rgb,
		scale_color(light->rgb, intensity * light->brghtnss * diffuse_factor)  // Luz difusa
	);
}


// static void	calculate_shadows(t_ray *ray, t_hit_data *hitd, t_light *light)
// {
// 	double	dist;
// 	double	intensity;
// 	double	t;
// 	t_vec3	quad;
	
// 	quad.x = 1;
// 	quad.y = 0.1;
// 	quad.z = 0.01;

// 	// dist = length_v3(sub_v3(hitd->hit, light.pos));
// 	dist = ray->length;
// 	t_vec3 src_ray = ray->direction;
// 	// t_vec3 src_ray = scale_v3(ray->ray, -1);
// 	t = (1 - light->brghtnss) * dot(&hitd->out_normal, &src_ray);
// 	// hitd->rgb = sum_rgb(hitd->rgb, scale_color(lightc, t));
// 	intensity = 1 / (quad.x + (quad.y * dist) + (quad.z * sqrt(dist))); 
// 	//hitd->rgb = sum_rgb(hitd->rgb, light->rgb);
// 	hitd->rgb = sum_rgb(scale_color(hitd->rgb, (1 - (intensity))) , scale_color(light->rgb, intensity * light->brghtnss));
// }

// // static void	calculate_shadows(t_hit_data *hitd)
// // {

// // }

void	calculate_lights(t_hit_data *hitd)
{
	t_lst	*lights;
	t_light	*light;
	t_scene *scn;
	t_ray	ray;
	t_interval	lim;
	t_hit_data hitl;

	hitl = *hitd;
	scn = get_scene();
	lights = scn->lights;
	init_limits(&lim, 0.001, INFINITY);
	while (lights)
	{
		light = (t_light *)lights->cnt;
		ray = init_ray(&hitd->hit, &light->pos);
		calculate_shadows(&ray, hitd, light);
		if (hit(&ray, &lim, &hitl))
		{
			// calculate_shadows(&ray, hitd, light);
			//calculate_shadows(hitd);
			hitd->rgb = scale_color(sum_rgb(hitl.rgb,hitd->orgb), hitd->t);
		}
		lights = lights->next;
	}
}