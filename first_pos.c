/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_pos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:09:19 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 07:47:58 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	first_pos(t_e *e)
{
	int j;

	e->i = 0;
	while (e->i < e->size_map.y)
	{
		j = -1;
		while (++j < e->size_map.x)
		{
			if (e->map[e->i][j] == e->me)
			{
				e->coor_me = push_back_coor(e->coor_me, e->me, e->i, j);
			}
			if (e->map[e->i][j] == e->en)
			{
				if (!(e->coor_en))
					init_bloc_en(e, e->i, j);
				mem_bloc_en(e, e->i, j);
				e->coor_en = push_back_coor(e->coor_en, e->en, e->i, j);
				e->nb_en++;
				e->nb_en_new++;
			}
		}
		e->i++;
	}
	e->nb_me = 1;
}
