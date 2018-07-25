/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:07:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/24 17:02:22 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <draw.h>
#include "../minilibx/mlx.h"
#include <read.h>

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
	t_rt		*rt;

	if ((rt = init_rt()) == 0)
		return (-1);
	read_file(rt, ac, av);	
	render(rt);
	mlx_hook(rt->win, 2, 0, handle_keys, rt);
	mlx_loop(rt->mlx);
	return (0);
}
