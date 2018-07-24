/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 15:08:55 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 17:44:43 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READ_H
# define READ_H

# include <rtv1.h>
# include <fcntl.h>
# include "../libft/gnl/get_next_line.h"
# include "../libft/printf/ft_printf.h"
# include <obj_make.h>

int		read_file(t_rt *rt, int ac, char **av);

#endif
