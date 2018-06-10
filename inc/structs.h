/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:07:24 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/09 16:47:56 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_ray
{
	t_vector	o;
	t_vector	d;
}				t_ray;

typedef struct	s_sphere
{
	t_vector	o;
	double		r;
	int			color;
}				t_sphere;

typedef struct	s_cam
{
	t_vector	o;
}				t_cam;

typedef struct	s_img
{
	void		*ptr;
	char		*data_addr;
	int			bpp;
	int			line_size;
	int			endian;
}				t_img;

typedef	struct	s_rt
{
	void		*mlx;
	void		*win;
	t_img		*img;
	t_cam		*cam;
}				t_rt;

#endif
