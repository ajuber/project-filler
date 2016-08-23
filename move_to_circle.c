/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:13:57 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 06:56:07 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_circle(t_e *e, t_pos cir)
{
	t_coor_piece *tmp;
	int				j;

	e->dist_center_me = -1;
	e->i = 0;
	tmp = e->coor_me;
	while (e->i < e->nb_me)
	{
		j = 0;
		ft_printf_fd(e->fd, "%d\n", e->i);
		if (!(search_point_to(e, e->dist_center_me, cir)))
			return (0);
		e->dist_center_me = calc_dist_to(cir, e->me_pos);
		while (j < e->nb_point)
		{
			if (check_place(e, j))
			{
				if (new_dist_to(e, cir))
				{
					print_coord(e);
					mem_coord_me(e);
					print_coord_me(e);
					return (1);
				}
			}
			j++;
		}
		ft_printf_fd(e->fd, "sss\n");
		tmp = tmp->next;
		ft_printf_fd(e->fd, "sss\n");
		e->i++;
	}
	return (0);
}
