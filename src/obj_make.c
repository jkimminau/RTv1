/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_make.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:26:16 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 21:24:54 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <obj_make.h>
#include <stdio.h>

void	make_light(t_rt *rt, char *line, int i)
{
	t_light		*light;

	light = (t_light *)malloc(sizeof(t_light));
	line = ft_nextword(ft_nextword(line));
	light->o.x = ft_atoi(line);
	line = ft_nextword(line);
	light->o.y = ft_atoi(line);
	line = ft_nextword(line);
	light->o.z = ft_atoi(line);
	line = ft_nextword(ft_nextword(ft_nextword(ft_nextword(line))));
	light->blue = (float)ft_atoi(line) / 10;
	line = ft_nextword(line);
	light->green = (float)ft_atoi(line) / 10;
	line = ft_nextword(line);
	light->red = (float)ft_atoi(line) / 10;
	rt->light_list[i] = light;
}

void	make_sphere(t_rt *rt, char *line, int i)
{
	t_sphere	*sphere;

	sphere = (t_sphere *)malloc(sizeof(t_sphere));
	line = ft_nextword(ft_nextword(line));	
	sphere->o.x = ft_atoi(line);
	line = ft_nextword(line);
	sphere->o.y = ft_atoi(line);
	line = ft_nextword(line);
	sphere->o.z = ft_atoi(line);
	line = ft_nextword(ft_nextword(ft_nextword(line)));
	sphere->r = ft_atoi(line);
	line = ft_nextword(ft_nextword(ft_nextword(line)));
	sphere->m.color.blue = ft_atoi(line);
	line = ft_nextword(line);
	sphere->m.color.green = ft_atoi(line);
	line = ft_nextword(line);
	sphere->m.color.red = ft_atoi(line);
	line = ft_nextword(line);
	sphere->m.reflection = (float)ft_atoi(line) / 10;
	rt->sphere_list[i] = sphere;
}

void	make_plane(t_rt *rt, char *line, int i)
{

}

