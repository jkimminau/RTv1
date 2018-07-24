/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_make.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkimmina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/23 17:24:14 by jkimmina          #+#    #+#             */
/*   Updated: 2018/07/23 21:03:43 by jkimmina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJ_MAKE_H
# define OBJ_MAKE_H

# include <rtv1.h>

void	make_light(t_rt *rt, char *line, int i);
void	make_sphere(t_rt *rt, char *line, int i);
void	make_plane(t_rt *rt, char *line, int i);

#endif
