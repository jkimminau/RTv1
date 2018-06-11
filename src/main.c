/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:07:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/10 22:10:51 by jkimmina         ###   ########.fr       */
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
	t_sphere	s[3];
	t_ray		cam;
	int			i;
	int			j;
	int			k;
	void		*mlx;
	void		*win;
	t_img		*img;

	if (!(mlx = mlx_init()))
		return (-1);
	if (!(win = mlx_new_window(mlx, WIN_WID, WIN_LEN, "RTv1 - 42")))
		return (-1);
	img = init_img(mlx);
	s[0].o.x = 500;
	s[0].o.y = 400;
	s[0].o.z = 5;
	s[0].r = 100;
	s[0].color = 0xff;

	s[1].o.x = 600;
	s[1].o.y = 400;
	s[1].o.z = 10;
	s[1].r = 50;
	s[1].color = 0xff00;

	s[2].o.x = 400;
	s[2].o.y = 400;
	s[2].o.z = 10;
	s[2].r = 150;
	s[2].color = 0xff0000;

	i = 0;
	while (i < WIN_LEN)
	{
		j = 0;
		while (j < WIN_WID)
		{
			cam.d.x = 0;
			cam.d.y = 0;
			cam.d.z = 1;
			cam.o.y = i;
			cam.o.x = j;
			cam.o.z = 0;
			cam.inter = 0;
			k = 0;
			while (k < 3)
				sphere_intersect(&cam, s[k++]);
			if (cam.inter != 0)
				img_pixel_put(img, j, i, cam.draw_color);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, win, img->ptr, 0, 0);
	mlx_loop(mlx);
	return (0);
}
