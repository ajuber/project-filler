/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 06:11:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 03:42:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_random(t_e *e)
{
	t_coor_piece *tmp;
	int				j;

	ft_printf_fd(e->fd2, "move_to_random\n");
	e->i = 0;
	tmp = e->coor_me;
	while (tmp && tmp->valid == 0)
		tmp = tmp->next;
	ft_printf_fd(e->fd, "ici\n");
	while (e->i < e->nb_me)
	{
		e->me_pos = tmp->pos;
		j = 0;
		while (j < e->nb_point)
		{
			if (check_place(e, j))
			{
				print_coord(e);
				mem_coord_me(e);
				print_coord_me(e);
				return (1);
			}
			j++;
		}
		tmp = tmp->next;
		while (tmp && tmp->valid == 0)
			tmp = tmp->next;
		e->i++;
	}
	return (0);
}
