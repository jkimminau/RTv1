/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:51:48 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 17:23:22 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <init.h>


t_rt		*rt_free(t_rt *rt)
{
	if (rt->win != 0)
		mlx_destroy_window(rt->mlx, rt->win);
	if (rt->mlx != 0)
		mlx_del(rt->mlx);
	free(rt);
	return (0);
}

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

t_rt	*init_rt(void)
{
		t_rt	*rt;

		if (!(rt = (t_rt *)malloc(sizeof(t_rt))))
			return (0);
		if (!(rt->mlx = mlx_init()))
			return (0);
		if (!(rt->win = mlx_new_window(rt->mlx, WIN_WID, WIN_LEN, "RTv1 - 42")))
			return (0);
		if (!(rt->img = init_img(rt->mlx)))
			return (0);
		return (rt);
}
