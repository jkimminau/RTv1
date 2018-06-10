/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:07:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/09 16:53:43 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <rtv1.h>

/*int		get_option(int ac, char **av)
{
	if (ac > 2)
		return (-1);
	if (ac == 1 || ft_strcmp(av[1], "1") == 0)
		return (1);
	if (ft_strcmp(av[1], "2") == 0)
		return (2);
	if (ft_strcmp(av[1], "3") == 0)
		return (3);
	return (-1);
}*/

t_img	*init_img(void *mlx)
{
	t_img	*img;

	if (!(img = (t_img *)malloc(sizeof(t_img))))
		return (0);
	if (!(img->ptr = mlx_new_image(mlx, WIN_WID, WIN_LEN)))
		return (0);
	img->data_addr = mlx_get_data_addr(img->ptr, &img->bpp,
			&img->line_size, &img->endian);
	img->bpp /= 8;
	return (img);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_sphere	s;
	t_sphere	s2;
	t_ray		r;
	int			i;
	int			j;
	void		*mlx;
	void		*win;
	t_img		*img;

	if (!(mlx = mlx_init()))
		return (-1);
	if (!(win = mlx_new_window(mlx, WIN_WID, WIN_LEN, "RTv1 - 42")))
		return (-1);
	img = init_img(mlx);
	s.o.x = 500;
	s.o.y = 400;
	s.o.z = 5;
	s.r = 100;
	s.color = 0xff;

	s2.o.x = 600;
	s2.o.y = 400;
	s2.o.z = 5000;
	s2.r = 100;
	s2.color = 0xff00;

	r.d.x = 0;
	r.d.y = 0;
	r.d.z = 1;
	r.o.z = 0;
	i = 0;
	while (i < WIN_LEN)
	{
		r.o.y = i;
		j = 0;
		while (j < WIN_WID)
		{
			r.o.x = j;
			if (sphere_intersect(r, s2))
				img_pixel_put(img, j, i, s2.color);
			if (sphere_intersect(r, s))
				img_pixel_put(img, j, i, s.color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, img->ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}
