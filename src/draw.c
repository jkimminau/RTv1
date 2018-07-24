/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:56:10 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 18:19:29 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>
#include <stdio.h>
#include <pthread.h>

void img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WID && y >= 0 && y < WIN_LEN)
		*(int *)(img->data_addr + ((x + y * WIN_WID) * img->bpp)) = color;	
}

void	*draw_thread(void *thread)
{
	int		x;
	int		y;
	int		res;
	t_rt		*rt;
	t_color	color;
	t_ray	ray;

	rt = (t_rt *)((t_thread *)thread)->rt;
	y = ((t_thread *)thread)->i;
	while (y < WIN_LEN)
	{
		x = 0;
		while (x < WIN_WID)
		{
			ray.d.x = 0;
			ray.d.y = 0;
			ray.d.z = 1;
			ray.o.x = x;
			ray.o.y = y;
			ray.o.z = -2000;
			color = calculate_ray(rt, &ray);
			color.blue = (color.blue > 255) ? 255 : color.blue;
			color.green = (color.green > 255) ? 255 : color.green;
			color.red = (color.red > 255) ? 255 : color.red;
			res = color.blue + (color.green << 8) + (color.red << 16);
			img_pixel_put(rt->img, x, y, res);
			x++;
		}
		y += THREADS;
	}
	return (NULL);	
}

void	render(t_rt *rt)
{
	t_thread	list[THREADS];
	int		i;

	i = 0;
	while (i < THREADS)
	{
		list[i].i = i;
		list[i].rt = rt;
		pthread_create(&(list[i]).tid, NULL, draw_thread, &list[i]);
		i++;
	}
	i = 0;
	while (i < THREADS)
		pthread_join(list[i++].tid, NULL);
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->ptr, 0, 0);
}
