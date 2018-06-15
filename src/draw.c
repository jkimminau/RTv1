/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:56:10 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/14 21:20:02 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

void img_pixel_put(t_img *img, int x, int y, int color)
{
	if (x >= 0 && x < WIN_WID && y >= 0 && y < WIN_LEN)
		*(int *)(img->data_addr + ((x + y * WIN_WID) * img->bpp)) = color;	
}

void	render(t_rt *rt)
{
	int		x;
	int		y;
	t_ray	ray;

	ray.d.x = 0;
	ray.d.y = 0;
	ray.d.z = 1;
	ray.o.z = 0;
	y = 0;
	while (y < WIN_LEN)
	{
		ray.o.y = y;
		x = 0;
		while (x < WIN_WID)
		{
			ray.o.x = x;
			img_pixel_put(rt->img, x, y, calculate_ray(rt, ray));
			x++;
		}
		//printf("y = %d\n", y);
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->ptr, 0, 0);
}
