/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/10 20:26:28 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 21:04:27 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VEC_MATH_H
# define VEC_MATH_H

# include <rtv1.h>

double		dot_product(t_vector v1, t_vector v2);
t_vector	vector_subtract(t_vector v1, t_vector v2);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_scale(double scale, t_vector v);

#endif
