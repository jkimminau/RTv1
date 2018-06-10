/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:11:30 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/09 16:53:57 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# define WIN_WID	1000
# define WIN_LEN	800
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
//# include <fcntl.h>
//# include <pthread.h>
//# include "../libft/libft.h"
# include "../minilibx/mlx.h"
# include <structs.h>

void		img_pixel_put(t_img *img, int x, int y, int color);
double		dot_product(t_vector v1, t_vector v2);
t_vector	vector_subtract(t_vector v1, t_vector v2);
int			sphere_intersect(t_ray r, t_sphere s);

#endif
