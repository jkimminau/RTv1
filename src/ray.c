/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 15:21:58 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/13 18:52:29 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <vec_math.h>
#include <math.h>
#include <rtv1.h>	//replace with obj_math.h

int		calculate_color(t_rt *rt, t_ray *bounce_ray, double reflection)
{
	t_vector	dist;
	t_light		light;
	t_ray		light_ray;
	double		t;
	double		l_ratio;
	int			i;
	int			color;

	(void)rt;
	i = 0;
	while (i < 4)//lightnum
	{
		dist = vector_subtract(light.o, bounce_ray->o);
		t = sqrt(dot_product(dist, dist));
		if (dot_product(dist, bounce_ray->d) && (t > 0.0))
		{
			light_ray.o = bounce_ray->o;
			light_ray.d = vector_scale(1.0 / t, dist);
			//lambert diffusion
			l_ratio = dot_product(light_ray.d, bounce_ray->d) * reflection;
			//color = l_ratio * lights[i].blue; // * material.diffuse.blue
			//color += (l_ratio * lights[i].green) << 8; // * material.diffuse.green
			//color += (l_ratio * lights[i].red) << 16; // * material.diffuse.red
		}
	}
	color = 0;
	return (color);
}

int		calculate_ray(t_rt *rt, t_ray ray)
{
	int			level;
	int			color;
	t_sphere	sphere;
	double		reflection;
	double		vec_product;
	t_ray		bounce_ray;
	//t_ray		normal_ray;

	level = 0;
	reflection = 1.0;
	while (level < 15 && reflection > 0.0)
	{
		sphere_intersect(&ray, sphere);
		if (ray.inter == 0.0)
			return (0);
		bounce_ray.o = vector_add(ray.o, vector_scale(ray.inter, ray.d));
		bounce_ray.d = vector_subtract(bounce_ray.o, sphere.o);
		if ((vec_product = dot_product(bounce_ray.d, bounce_ray.d)) == 0)
			return 0;
		bounce_ray.d = vector_scale(1.0 / sqrtf(vec_product), bounce_ray.d);
		color = calculate_color(rt, &bounce_ray, reflection);
		reflection *= 0.4;
		ray.o = bounce_ray.o;
		ray.d = vector_subtract(ray.d, vector_scale(2.0 * dot_product(ray.d, bounce_ray.d), bounce_ray.d));
		level++;
	}
	return (color);
}

void	render(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;

	ray.d.x = 0;
	ray.d.y = 0;
	ray.d.z = 1;
	ray.o.z = 0;
	y = 0;
	while (y < WIN_LEN)
	{
		ray.o.y = y;
		x = 0;
		while (x < WIN_WID)
		{
			//reset ray
			ray.o.x = x;
			img_pixel_put(rt->img, x, y, calculate_ray(rt, ray));
			x++;
		}
		y++;
	}
}
