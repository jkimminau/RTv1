/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:07:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/20 15:57:05 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <draw.h>
#include "../minilibx/mlx.h"

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

int		handle_keys(int key, t_rt *rt)
{
	if (key == 53)
	{
		rt_free(rt);
		exit(0);
	}
	if (key == 123 || key == 124)
		rt->light_list[0]->o.x += (key > 123) ? 10 : -10;
	if (key == 1 || key == 13)
		rt->light_list[0]->o.z += (key > 1) ? 10 : -10;
	if (key == 125 || key == 126)
		rt->light_list[0]->o.y += (key > 125) ? -10 : 10;
	render(rt);
	return (0);
}

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_rt		*rt;

	if ((rt = init_rt()) == 0)
		return (-1);

	rt->material_list = (t_material *)malloc(sizeof(t_material) * 3);
	rt->material_list[0].color.red = 0;
	rt->material_list[0].color.green = 0;
	rt->material_list[0].color.blue = 255;
	rt->material_list[0].reflection = 0.4;

	rt->material_list[1].color.red = 0;
	rt->material_list[1].color.green = 255;
	rt->material_list[1].color.blue = 0;
	rt->material_list[1].reflection = 0.4;

	rt->material_list[2].color.red = 255;
	rt->material_list[2].color.green = 0;
	rt->material_list[2].color.blue = 0;
	rt->material_list[2].reflection = 0.4;

	rt->sphere_list = (t_sphere **)malloc(sizeof(t_sphere *) * 4);
	rt->sphere_list[0] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[0]->o.x = 300;
	rt->sphere_list[0]->o.y = 400;
	rt->sphere_list[0]->o.z = 50;
	rt->sphere_list[0]->r = 70;
	rt->sphere_list[0]->m = &rt->material_list[0];

	rt->sphere_list[1] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[1]->o.x = 700;
	rt->sphere_list[1]->o.y = 400;
	rt->sphere_list[1]->o.z = 50;
	rt->sphere_list[1]->r = 70;
	rt->sphere_list[1]->m = &rt->material_list[1];

	rt->sphere_list[2] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[2]->o.x = 500;
	rt->sphere_list[2]->o.y = 400;
	rt->sphere_list[2]->o.z = 50;
	rt->sphere_list[2]->r = 70;
	rt->sphere_list[2]->m = &rt->material_list[2];
	
	rt->sphere_list[3] = 0;
	
	rt->light_list = (t_light **)malloc(sizeof(t_light *) * 1);
	rt->light_list[0] = (t_light *)malloc(sizeof(t_light));
	rt->light_list[0]->o.x = 500;
	rt->light_list[0]->o.y = 0;
	rt->light_list[0]->o.z = -500;
	rt->light_list[0]->blue = 1.0;
	rt->light_list[0]->green = 1.0;
	rt->light_list[0]->red = 1.0;

	render(rt);

	//mlx_key_hook(rt->win, handle_keys, rt);
	mlx_hook(rt->win, 2, 0, handle_keys, rt);
	mlx_loop(rt->mlx);
	return (0);
}
