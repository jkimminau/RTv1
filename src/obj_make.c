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
	printf("light[%d]: (%f, %f, %f) (%f, %f, %f)\n", i, light->o.x, light->o.y, light->o.z, light->blue, light->green, light->red);
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
	printf("sphere[%d]: (%f, %f, %f) %f (%d, %d, %d, %f)\n", i, sphere->o.x, sphere->o.y, sphere->o.z, sphere->r, sphere->m.color.blue, sphere->m.color.green, sphere->m.color.red, sphere->m.reflection);
}

void	make_plane(t_rt *rt, char *line, int i)
{
	t_plane		*plane;

	plane = (t_plane *)malloc(sizeof(t_plane));
	line = ft_nextword(ft_nextword(line));
	plane->o.x = ft_atoi(line);	
	plane->o.y = ft_atoi(ft_nextword(line));	
	plane->o.z = ft_atoi(ft_nextword(ft_nextword(line)));
	line = ft_nextword(ft_nextword(ft_nextword(ft_nextword(ft_nextword(ft_nextword(line))))));
	plane->n.x = ft_atoi(line);
	plane->n.y = ft_atoi(ft_nextword(line));
	plane->n.z = ft_atoi(ft_nextword(ft_nextword(line)));
	line = ft_nextword(ft_nextword(ft_nextword(ft_nextword(ft_nextword(ft_nextword(line))))));
	plane->m.color.blue = ft_atoi(line);
	plane->m.color.green = ft_atoi(ft_nextword(line));
	plane->m.color.red = ft_atoi(ft_nextword(ft_nextword(line)));
	plane->m.reflection = (float)ft_atoi(ft_nextword(ft_nextword(ft_nextword(line)))) / 10;
	rt->plane_list[i] = plane;
	printf("plane[%d]: (%f, %f, %f) (%f, %f, %f) (%d, %d, %d, %f)\n", i, plane->o.x, plane->o.y, plane->o.z, plane->n.x, plane->n.y, plane->n.z, plane->m.color.blue, plane->m.color.green, plane->m.color.red, plane->m.reflection);
}
