/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 14:07:24 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 18:52:37 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

#include <pthread.h>

typedef struct	s_color
{
	int			red;
	int			green;
	int			blue;
}		t_color;

typedef struct	s_material
{
	t_color		color;
	float		reflection;
}		t_material;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
}				t_vector;

typedef struct	s_plane
{
	t_vector	o;
	t_vector	n;
	t_material	m;
}				t_plane;

typedef struct	s_sphere
{
	t_vector	o;
	float		r;
	t_material	m;
}				t_sphere;

typedef struct	s_ray
{
	t_vector	o;
	t_vector	d;
	t_color		color;
	float		intersect;
	t_vector	obj_o;
	t_material	m;
}				t_ray;

typedef struct	s_light
{
	t_vectorsssssssso;
	float		red;
	float		green;
	float		blue;
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
	t_img		*img;
	t_sphere	**sphere_list;
	int			sphere_list_size;
	t_plane		**plane_list;
	int			plane_list_size;
	t_light		**light_list;
	int			light_list_size;
}				t_rt;

typedef struct	s_thread
{
	pthread_t		tid;
	int			i;
	t_rt			*rt;
}				t_thread;
#endif
