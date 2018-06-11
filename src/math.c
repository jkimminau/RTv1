/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:36:09 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/10 22:10:49 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <structs.h>
#include <math.h>
#include <stdio.h>
#include <vec_math.h>

int			sphere_intersect(t_ray *r, t_sphere s)
{
	double		a;
	double		b;
	double		c;
	double		inter0;
	double		inter1;
	double		disc;
	t_vector	dist;

	a = dot_product(r->d, r->d);
	dist = vector_subtract(r->o, s.o);
	b = 2 * dot_product(r->d, dist);
	c = dot_product(dist, dist) - (s.r * s.r);
	disc = (b * b) - (4 * a * c);
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	inter0 = (-b + disc) / 2;
	inter1 = (-b - disc) / 2;
	if (inter0 > inter1)
		inter0 = inter1;
	if (r->inter == 0.0 || (inter0 > 0.001 && inter0 < r->inter))
	{
		r->inter = inter0;
		r->draw_color = s.color;
		return (1);
	}
	return (0);
}
