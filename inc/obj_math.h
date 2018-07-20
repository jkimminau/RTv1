/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:48:45 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/20 15:35:35 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_MATH_H
# define OBJ_MATH_H

#include <rtv1.h>
#include <vec_math.h>

int		sphere_intersect(t_ray *r, t_sphere *s);
int		plane_intersect(t_ray *r, t_plane p);

#endif
