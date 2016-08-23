/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:52:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 12:05:49 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_mid(t_e *e)
{
	t_coor_piece *tmp;
	int				j;

//	ft_printf_fd(e->fd, "ici\n");
	e->dist_center_me = -1;
	e->i = 0;
	tmp = e->coor_me;
//	ft_printf_fd(e->fd, "ici\n");
	while (e->i < e->nb_me)
	{
		j = 0;
//		ft_printf_fd(e->fd, "pendant move_to_mid avant search_point_to_mid\n");
//		ft_printf_fd(e->fd, "%d\n",e->i);
		if (!(search_point_to_mid(e, e->dist_center_me)))
			return (0);
//		ft_printf_fd(e->fd, "pendant move_to_mid apres search_point_to_mid\n");
//		ft_printf_fd(e->fd1, "pos_me.y : %d     pos_me.x : %d\n", e->me_pos.y, e->me_pos.x);
		e->dist_center_me = calc_dist_to_center(e, e->me_pos);
		if (e->dist_center_me < 3)
			return (2);
//		ft_printf_fd(e->fd1, "dist to center : %d\n", e->dist_center_me);
//		ft_printf_fd(e->fd1, "center.y : %d       center.x : %d\n", e->center.y, e->center.x);
		while (j < e->nb_point)
		{
			if (check_place(e, j))
			{
				if (new_dist_to_center(e))
				{
					print_coord(e);
					mem_coord_me(e);
				//	print_coord_me(e);
					return (1);
				}
			}
			j++;
		}
//		ft_printf_fd(e->fd, "ssss\n");
		tmp = tmp->next;
//		ft_printf_fd(e->fd, "ssss\n");
		e->i++;
	}
	return (0);
}
