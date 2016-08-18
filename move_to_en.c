/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_en.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:58:49 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/17 23:30:51 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_en(t_e *e)
{
	t_coor_piece *tmp;
	int				j;

	ft_printf_fd(e->fd, "ici\n");
	e->dist_me_en = -1;
	e->i = 0;
	tmp = e->coor_me;
	ft_printf_fd(e->fd, "ici\n");
	while (e->i < e->nb_me)
	{
		j = 0;
		ft_printf_fd(e->fd, "pendant move_to_mid avant search_point_to_mid\n");
		if (!(search_point_to_en(e, e->dist_me_en)))
			return (0);
		ft_printf_fd(e->fd, "pendant move_to_mid apres search_point_to_mid\n");
		ft_printf_fd(e->fd1, "pos_me.y : %d     pos_me.x : %d\n", e->me_pos.y, e->me_pos.x);
		e->dist_me_en = calc_dist_to_en(e, e->me_pos);
		if (e->dist_me_en < 3)
			return (2);
		ft_printf_fd(e->fd1, "dist to center : %d\n", e->dist_center_me);
		ft_printf_fd(e->fd1, "center.y : %d       center.x : %d\n", e->center.y, e->center.x);
		while (j < e->nb_point)
		{
			if (check_place(e, j))
			{
				if (new_dist_to_en(e))
				{
					print_coord(e);
					mem_coord_me(e);
					print_coord_me(e);
					print_coord_en(e);
					return (1);
				}
			}
			j++;
		}
		tmp = tmp->next;
		e->i++;
	}
	return (0);
}
