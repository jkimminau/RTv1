/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:58 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/15 17:57:43 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <stdlib.h>
#include <stdio.h>

t_color		calculate_color(t_rt *rt, t_ray *normal, double reflection, t_ray *ray)
{
	t_vector	dist;
	t_light		light;
	t_ray		lightray;
	double		t;
	double		l_ratio;
	//int			i;
	int			j;

	(void)rt;
	light.o.x = 500;
	light.o.y = 200;
	light.o.z = -50;
	light.blue = 1.0;
	light.green = 0.7;
	light.red = 0.7;
	/*i = 0;
	while (i < 1)	//For each light
	{*/
		dist = vector_subtract(light.o, normal->o);
		t = sqrt(dot_product(dist, dist));
		if (dot_product(dist, normal->d) && (t > 0.0))
		{
			lightray.o = normal->o;
			lightray.d = vector_scale(1.0 / t, dist);
			
			j = 0;
			lightray.intersect = 0.0;
			while (rt->sphere_list[j] != 0)
				sphere_intersect(&lightray, rt->sphere_list[j++]);
			if (lightray.intersect != 0.0)
				return (ray->color);
			
			//lambert diffusion
			//printf("reflection: %f\n", reflection);
			//printf("lightray(%f, %f, %f)\n", lightray.o.x, lightray.o.y, lightray.o.z);
			//printf("dot product: %f\n", dot_product(lightray.d, normal->d));
			l_ratio = dot_product(lightray.d, normal->d) * reflection;
			//printf("l_ratio = %f\n", l_ratio);
			ray->color.blue += l_ratio * light.blue * normal->obj->m->color.blue;
			ray->color.green += l_ratio * light.green * normal->obj->m->color.green;
			ray->color.red += l_ratio * light.red * normal->obj->m->color.red;
		}
		/*i++;
	}*/
	return (ray->color);
}

t_color		calculate_ray(t_rt *rt, t_ray *ray)
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
	ray->color.blue = 0;
	ray->color.green = 0;
	ray->color.red = 0;
	while (level < 15 && reflection > 0)
	{
		//get intersection
		//printf("[%f, %f, %f]\n", ray->o.x, ray->o.y, ray->o.z);
		ray->intersect = 0.0;
		i = 0;
		while (rt->sphere_list[i] != 0)
			sphere_intersect(ray, rt->sphere_list[i++]);
		if (ray->intersect == 0.0)
			return (ray->color);
		normal.obj = ray->obj;

		//get intersection
		normal.o =	vector_scale(ray->intersect, ray->d);	//new start
		printf("[%f, %f, %f]\n", ray->o.x, ray->o.y, ray->o.z);
		normal.o = vector_add(ray->o, vector_scale(ray->intersect, ray->d));	//new start
		//printf("[%f, %f, %f]\n", normal.o.x, normal.o.y, normal.o.z);

		normal.d = vector_subtract(normal.o, normal.obj->o);
		if ((vec_product = dot_product(normal.d, normal.d)) == 0)
			return (ray->color);
		normal.d = vector_scale(1.0 / sqrtf(vec_product), normal.d);
		ray->color = calculate_color(rt, &normal, reflection, ray);
		reflection *= ray->obj->m->reflection;
		ray->o = normal.o;
		ray->d = vector_subtract(ray->d, vector_scale(2.0 * dot_product(ray->d, normal.d), normal.d));
		level++;
		//printf("level = %d\tref = %f\n", level, reflection);
	}
	//ray->color = &ray->obj->mat->color;
	return (ray->color);
}
