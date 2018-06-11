/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:21:10 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/10 21:03:09 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vec_math.h>

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

t_vector	vector_add(t_vector v1, t_vector v2)
{
	t_vector	result;

	result.x = v1.x + v2.x;
	result.y = v1.y + v2.y;
	result.z = v1.z + v2.z;
	return (result);
}

t_vector	vector_scale(double scale, t_vector v)
{
	t_vector	result;

	result.x = v.x * scale;
	result.y = v.y * scale;
	result.z = v.z * scale;
	return (result);
}

