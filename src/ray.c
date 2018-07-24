/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:58 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 21:22:07 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray.h>
#include <stdlib.h>
#include <stdio.h>

void		calculate_color(t_rt *rt, t_ray *normal, double r, t_ray *ray)
{
	t_vector	dist;
	t_ray		lightray;
	float		t;
	float		l_ratio;
	int		i;
	int		j;

	i = 0;
	while (i < rt->light_list_size)
	{
		dist = vector_subtract(rt->light_list[i]->o, normal->o);
		t = sqrt(dot_product(dist, dist));
		if (dot_product(dist, normal->d) > 0.0 && (t > 0.0))
		{
			lightray.o = normal->o;
			lightray.d = vector_scale(1.0 / t, dist);
			j = 0;
			get_intersect(rt, &lightray);
			if (lightray.intersect != 0.0)
				return ;
			l_ratio = dot_product(lightray.d, normal->d) * r;
			ray->color.blue += l_ratio * rt->light_list[i]->blue * normal->m.color.blue;
			ray->color.green += l_ratio * rt->light_list[i]->green * normal->m.color.green;
			ray->color.red += l_ratio * rt->light_list[i]->red * normal->m.color.red;
		}
		i++;
	}
}

t_color		calculate_ray(t_rt *rt, t_ray *ray)
{
	int			level;
	float		reflection;
	float		vec_product;
	t_ray		normal;
	
	ray->color.blue = 0;
	ray->color.green = 0;
	ray->color.red = 0;

	level = 0;
	reflection = 1.0;
	while (level < 1 && reflection > 0)
	{
		get_intersect(rt, ray);
		if (ray->intersect == 0.0)
			return (ray->color);
		normal.obj_o = ray->obj_o;
		normal.m = ray->m;
		normal.o = vector_add(ray->o, vector_scale(ray->intersect, ray->d));
		normal.d = vector_subtract(normal.o, normal.obj_o);
		if ((vec_product = dot_product(normal.d, normal.d)) == 0)
			return (ray->color);
		normal.d = vector_scale(1.0 / sqrtf(vec_product), normal.d);
		calculate_color(rt, &normal, reflection, ray);
		reflection *= ray->m.reflection;
		ray->o = normal.o;
		ray->d = vector_subtract(ray->d, vector_scale(2.0 * dot_product(ray->d, normal.d), normal.d));
		level++;
	}
	return (ray->color);
}
