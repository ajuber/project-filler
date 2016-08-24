/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_coord_me.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:31:04 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:02:00 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		next(t_e *e, t_coor_piece **tmp)
{
	tmp[0] = e->coor_me;
	while (tmp[0]->next)
	{
		verif_valid_circle(e, tmp[0]->pos);
		tmp[0] = tmp[0]->next;
	}
}

void			mem_coord_me(t_e *e)
{
	int				j;
	t_pos			pos;
	t_coor_piece	*tmp;

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
	if (e->strat == 1)
		next(e, &tmp);
}
