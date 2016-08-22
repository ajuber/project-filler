/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 06:11:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/22 06:17:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_random(t_e *e)
{
	t_coor_piece *tmp;
	int				j;

	ft_printf_fd(e->fd, "ici\n");
	e->i = 0;
	tmp = e->coor_me;
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
		e->i++;
	}
	return (0);
}
