/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/09 15:56:10 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/16 18:23:16 by jkimmina         ###   ########.fr       */
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
	int		res;
	t_color	*color;
	t_ray	ray;

	ray.d.x = 0;
	ray.d.y = 0;
	ray.d.z = 1;
	ray.o.z = -2000;
	y = 0;
	while (y < WIN_LEN)
	{
		ray.o.y = y;
		x = 0;
		while (x < WIN_WID)
		{
			ray.o.x = x;
			color = calculate_ray(rt, &ray);
			if (color == 0)
				res = 0;
			else
			{
				printf("red: %d green: %d blue: %d\n", color->red, color->green, color->blue);
				res = color->blue + (color->green << 8) + (color->red << 16);
			}
			img_pixel_put(rt->img, x, y, res);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(rt->mlx, rt->win, rt->img->ptr, 0, 0);
}
