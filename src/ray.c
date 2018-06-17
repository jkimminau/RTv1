/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:58 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/16 18:29:03 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <stdio.h>

/*t_color		calculate_color(t_rt *rt, t_ray *normal, double reflection)
{
	t_vector	dist;
	t_light		light;
	t_ray		light_ray;
	double		t;
	double		l_ratio;
	int			i;
	int			color;

	(void)rt;
	light.o.x = 0;
	light.o.y = 100;
	light.o.z = 1;
	i = 0;
	color = 0;
	while (i < 1)//lightnum
	{
		dist = vector_subtract(light.o, normal->o);
		t = sqrt(dot_product(dist, dist));
		if (dot_product(dist, normal->d) && (t > 0.0))
		{
			light_ray.o = normal->o;
			light_ray.d = vector_scale(1.0 / t, dist);
			//lambert diffusion
			l_ratio = dot_product(light_ray.d, normal->d) * reflection;
			color = normal->obj->color;
			//color = l_ratio * lights[i].blue; // * material.diffuse.blue
			//color += (l_ratio * lights[i].green) << 8; // * material.diffuse.green
			//color += (l_ratio * lights[i].red) << 16; // * material.diffuse.red
		}
		i++;
	}
	return (color);
}*/

t_color		*calculate_ray(t_rt *rt, t_ray *ray)
{
	int			i;
	int			level;
	double		reflection;
	double		vec_product;
	t_ray		normal;

	(void)vec_product;
	(void)normal;
	level = 0;
	reflection = 1.0;
	while (level < 1 && reflection > 0.0)
	{
		//get intersection
		ray->inter = 0.0;
		i = 0;
		while (rt->sphere_list[i] != 0)
			sphere_intersect(ray, rt->sphere_list[i++]);
		if (ray->inter == 0.0)
			return (0);
		normal.obj = ray->obj;
		//get intersection
		normal.o = vector_add(ray->o, vector_scale(ray->inter, ray->d));
		normal.d = vector_subtract(normal.o, normal.obj->o);
		if ((vec_product = dot_product(normal.d, normal.d)) == 0)
			return (0);
		normal.d = vector_scale(1.0 / sqrtf(vec_product), normal.d);
		//color = calculate_color(rt, &normal, reflection);
		reflection *= 0.4;
		ray->o = normal.o;
		ray->d = vector_subtract(ray->d, vector_scale(2.0 * dot_product(ray->d, normal.d), normal.d));
		level++;
	}
	//printf("intersection at (%f,%f,%f)\n", ray.o.x, ray.o.y, ray.inter);
	return (&(ray->obj->mat->color));
}
