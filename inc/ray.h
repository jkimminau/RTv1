/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:09:09 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/16 21:50:47 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include <math.h>
#include <vec_math.h>
#include <obj_math.h>

t_color	*calculate_color(t_rt *rt, t_ray *bounce_ray, double reflection, t_ray *ray);
t_color	*calculate_ray(t_rt *rt, t_ray *ray);

#endif
