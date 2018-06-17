/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:07:24 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/16 20:49:48 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}				t_color;

typedef struct	s_material
{
	t_color		color;
	double		reflection;
}				t_material;

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_sphere
{
	t_vector	o;
	double		r;
	t_material	*mat;
}				t_sphere;

typedef struct	s_ray
{
	t_vector	o;
	t_vector	d;
	double		inter;
	t_color		*color;
	t_sphere	*obj;
}				t_ray;

typedef struct	s_light
{
	t_vector	o;
	double		red;
	double		green;
	double		blue;
}				t_light;

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
	t_sphere	**sphere_list;
	t_img		*img;
}				t_rt;

#endif
