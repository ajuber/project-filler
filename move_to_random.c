/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_random.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 06:11:36 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:13:38 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_random(t_e *e)
{
	t_coor_piece	*tmp;
	int				j;

	e->i = -1;
	tmp = e->coor_me;
	while (tmp && tmp->valid == 0)
		tmp = tmp->next;
	while (++e->i < e->nb_me)
	{
		e->me_pos = tmp->pos;
		j = -1;
		while (++j < e->nb_point)
		{
			if (check_place(e, j))
			{
				print_coord(e);
				mem_coord_me(e);
				return (1);
			}
		}
		tmp = tmp->next;
		while (tmp && tmp->valid == 0)
			tmp = tmp->next;
	}
	return (0);
}
