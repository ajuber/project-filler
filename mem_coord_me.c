/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_coord_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:31:04 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/15 09:23:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mem_coord_me(t_e *e)
{
	int j;
	t_pos pos;
	t_coor_piece *tmp;

	tmp = e->coor_piece;
	j = 0;
	while (j < e->nb_point)
	{
		if (tmp != e->repere)
		{
			pos = ft_pos_in_map(e->me_pos, e->repere->pos, tmp->pos);
			e->coor_me = push_back_coor(e->coor_me, e->me, pos.y, pos.x);
			e->nb_me++;
		}
		j++;
		tmp = tmp->next;
	}
}
