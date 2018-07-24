/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:11:20 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 21:22:19 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <read.h>

void	get_size(t_rt *rt, char *filename)
{
	int		fd;
	char	*line;

	rt->sphere_list_size = 0;
	rt->plane_list_size = 0;
	rt->light_list_size = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
			if (ft_strncmp("light", line, 5) == 0)
				rt->light_list_size++;
			if (ft_strncmp("sphere", line, 6) == 0)
				rt->sphere_list_size++;
			if (ft_strncmp("plane", line, 5) == 0)
				rt->plane_list_size++;
	}
	close (fd);
	rt->light_list = (rt->light_list_size > 0) ? malloc(sizeof(t_light *) * rt->light_list_size) : 0;
	rt->sphere_list = (rt->sphere_list_size > 0) ? malloc(sizeof(t_sphere *) * rt->sphere_list_size) : 0;
	rt->plane_list = (rt->plane_list_size > 0) ? malloc(sizeof(t_plane *) * rt->plane_list_size) : 0;
}

void	make_objects(t_rt *rt, char *filename)
{
	int		fd;
	char	*line;
	int		count[3];
	int		i;

	i = 0;
	while (i < 3)
		count[i++] = 0;
	fd = open(filename, O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
			if (ft_strncmp("light", line, 5) == 0)
				make_light(rt, ft_nextword(line), count[0]++); 
			if (ft_strncmp("sphere", line, 6) == 0)
				make_sphere(rt, ft_nextword(line), count[1]++); 
			if (ft_strncmp("plane", line, 5) == 0)
				make_plane(rt, ft_nextword(line), count[2]++); 
	}
	close (fd);
}

int		read_file(t_rt *rt, int ac, char **av)
{
	int		fd;

	(void)rt;
	if (ac != 2)
	{
		ft_printf("usage: ./RTv1 [filename]\n");
		return (0);
	}
	fd = open(av[1], O_RDONLY);
	if (fd == -1) 
	{
		ft_printf("error opening file '%s'\n", av[1]);
		return (0);
	}
	close(fd);
	get_size(rt, av[1]);
	make_objects(rt, av[1]);
	return (1);
}
