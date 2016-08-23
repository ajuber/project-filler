/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_coord.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 03:43:19 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 00:18:27 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	new_coord(t_e *e, char *map, char *line, int y)
{
	int		x;

	x = 0;
	while (x < e->size_map.x)
	{
		if (map[x] != line[x] && line[x] == e->en)
		{
			e->coor_en = push_back_coor(e->coor_en, e->en, y, x);
			mem_bloc_en(e, y, x);
			e->nb_en_new++;
		}
		x++;
	}
}
