/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 18:11:22 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/24 16:34:38 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DRAW_H
# define DRAW_H

# define THREADS 8

# include <ray.h>
# include <rtv1.h>

void	img_pixel_put(t_img *img, int x, int y, int color);
void	render(t_rt *rt);

#endif
