/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:48:34 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/15 17:54:24 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj_math.h>
#include <stdio.h>

int			sphere_intersect(t_ray *r, t_sphere *s)
{
	double		a;
	double		b;
	double		c;
	double		inter0;
	double		inter1;
	double		disc;
	t_vector	dist;

	a = dot_product(r->d, r->d);
	dist = vector_subtract(r->o, s->o);
	b = 2 * dot_product(r->d, dist);
	c = dot_product(dist, dist) - (s->r * s->r);
	//printf("dist: %f\n", dot_product(dist, dist));
	disc = (b * b) - (4 * a * c);

	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	inter0 = (-b + disc) / 2;
	inter1 = (-b - disc) / 2;
	if (inter0 > inter1)
		inter0 = inter1;
	if (inter0 > 0.00001 && (r->intersect == 0.0 || inter0 < r->intersect))
	{
		r->intersect = inter0;
		r->obj = s;
		return (1);
	}
	return (0);
}

int			plane_intersect(t_ray *r)
{
	
}
