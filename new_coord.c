/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 03:43:19 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 08:58:52 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	new_coord(t_e *e, char *map, char *line, int y)
{
	int		x;
	t_pos	pos;

	x = 0;
	while (x < e->size_map.x)
	{
		if (map[x] != line[x] && line[x] == e->en)
		{
			pos.y = y;
			pos.x = x;
			if (calc_dist_to_center(e, pos) <= 2)
				e->strat = 1;
			e->coor_en = push_back_coor(e->coor_en, e->en, y, x);
			mem_bloc_en(e, y, x);
			e->nb_en_new++;
		}
		x++;
	}
}
