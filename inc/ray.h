/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:09:09 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/14 18:59:42 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

#include <math.h>
#include <vec_math.h>
#include <obj_math.h>

int		calculate_color(t_rt *rt, t_ray *bounce_ray, double reflection);
int		calculate_ray(t_rt *rt, t_ray ray);

#endif
