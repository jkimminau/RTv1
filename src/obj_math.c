/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:48:34 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/24 16:27:44 by jkimmina         ###   ########.fr       */
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
	disc = (b * b) - (4 * a * c);
	if (disc < 0)
		return (0);
	disc = sqrt(disc);
	inter0 = (-b + disc) / 2;
	inter1 = (-b - disc) / 2;
	inter0 = (inter0 < inter1) ? inter0 : inter1;
	if (inter0 > 0.00001 && (r->intersect == 0.0 || inter0 < r->intersect))
	{
		r->intersect = inter0;
		r->obj_o = s->o;
		r->m = s->m;
		return (1);
	}
	return (0);
}

int			plane_intersect(t_ray *r, t_plane *p)
{
	float		inter;
	float		a;
	float		b;

	inter = 0.0;
	if ((a = dot_product(p->n, r->d)) == 0)
		return (0);
	b = dot_product(p->n, vector_subtract(r->o, p->o));
	inter = -b / a;
	if (inter > 0 && (r->intersect == 0.0 || inter < r->intersect))
	{
		r->intersect = inter;
		//r->obj_o = p->o;
		r->obj_o.x = r->o.x;
		r->obj_o.y = r->o.y;
		r->obj_o.z = inter - r->o.z;
		r->m = p->m;
		return (1);
	}
	return (0);
}

void	get_intersect(t_rt *rt, t_ray *ray)
{
	int		i;

	ray->intersect = 0.0;
	i = 0;
	while (i < rt->sphere_list_size)
		sphere_intersect(ray, rt->sphere_list[i++]);
	i = 0;
	while (i < rt->plane_list_size)
		plane_intersect(ray, rt->plane_list[i++]);
}
