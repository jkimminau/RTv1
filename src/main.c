/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 21:07:32 by jkimmina          #+#    #+#             */
/*   Updated: 2018/06/14 21:20:11 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <draw.h>

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

int		main(int ac, char **av)
{
	(void)ac;
	(void)av;
	t_rt		*rt;

	if ((rt = init_rt()) == 0)
		return (-1);
	rt->sphere_list = (t_sphere **)malloc(sizeof(t_sphere *) * 3);
	rt->sphere_list[0] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[0]->o.x = 500;
	rt->sphere_list[0]->o.y = 400;
	rt->sphere_list[0]->o.z = 5;
	rt->sphere_list[0]->r = 100;
	rt->sphere_list[0]->color = 0xff;

	rt->sphere_list[1] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[1]->o.x = 600;
	rt->sphere_list[1]->o.y = 400;
	rt->sphere_list[1]->o.z = 50;
	rt->sphere_list[1]->r = 50;
	rt->sphere_list[1]->color = 0xff00;
	rt->sphere_list[2] = 0;

	/*rt->sphere_list[2] = (t_sphere *)malloc(sizeof(t_sphere));
	rt->sphere_list[2]->o.x = 400;
	rt->sphere_list[2]->o.y = 400;
	rt->sphere_list[2]->o.z = 100;
	rt->sphere_list[2]->r = 150;
	rt->sphere_list[2]->color = 0xff0000;

	rt->sphere_list[3] = 0;*/
	render(rt);
	mlx_loop(rt->mlx);
	return (0);
}
