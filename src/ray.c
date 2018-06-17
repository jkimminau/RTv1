/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:58 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/16 21:55:29 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <stdlib.h>
#include <stdio.h>

t_color		*calculate_color(t_rt *rt, t_ray *normal, double reflection, t_ray *ray)
{
	t_vector	dist;
	t_light		light;
	t_ray		light_ray;
	double		t;
	double		l_ratio;
	int			i;

	(void)rt;
	light.o.x = 500;
	light.o.y = 300;
	light.o.z = 0;
	light.blue = 1.0;
	light.green = 0.7;
	light.red = 0.7;
	i = 0;
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
			printf("lratio: %f\n", l_ratio);
			ray->color->blue += l_ratio * light.blue * normal->obj->mat->color.blue;
			ray->color->green += l_ratio * light.green * normal->obj->mat->color.green;
			ray->color->red += l_ratio * light.red * normal->obj->mat->color.red;
		}
		i++;
	}
	return (ray->color);
}

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
	ray->color = (t_color *)malloc(sizeof(t_color));
	ray->color->blue = 0;
	ray->color->green = 0;
	ray->color->red = 0;
	while (level < 1 && reflection > 0)
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
		ray->color = calculate_color(rt, &normal, reflection, ray);
		reflection *= ray->obj->mat->reflection;
		ray->o = normal.o;
		ray->d = vector_subtract(ray->d, vector_scale(2.0 * dot_product(ray->d, normal.d), normal.d));
		level++;
		printf("color: [%d, %d, %d]\n", ray->color->blue, ray->color->green, ray->color->blue);
		//printf("level = %d\tref = %f\n", level, reflection);
	}
	//printf("(%d, %d, %d) at (%f,%f,%f)\n", ray->color->blue, ray->color->green, ray->color->red, ray->o.x, ray->o.y, ray->inter);
	//ray->color = &ray->obj->mat->color;
	return (ray->color);
}
