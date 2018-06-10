/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:36:09 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/09 16:53:26 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <stdio.h>

double		dot_product(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}	

t_vector	vector_subtract(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = (v1.x - v2.x);
	result.y = (v1.y - v2.y);
	result.z = (v1.z - v2.z);
	return (result);
}

int			sphere_intersect(t_ray r, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		disc;
	t_vector	dist;

	a = dot_product(r.d, r.d);
	dist = vector_subtract(r.o, s.o);
	b = 2 * dot_product(r.d, dist);
	c = dot_product(dist, dist) - (s.r * s.r);
	disc = (b * b) - (4 * a * c);
	if (disc >= 0)
		return (1);
	return (0);
}
