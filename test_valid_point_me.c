/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_point_me.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:30:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 13:05:01 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_valid(t_e *e, t_pos pos, t_coor_piece *p)
{
	if (pos.y - 1 >= 0 && pos.x - 1 >= 0 && e->map[pos.y - 1][pos.x - 1] == '.')
		return (1);
	if (pos.y - 1 >= 0 && e->map[pos.y - 1][pos.x] == '.')
		return (1);
	if (pos.y - 1 >= 0 && pos.x + 1 < e->size_map.x &&
			e->map[pos.y - 1][pos.x + 1] == '.')
		return (1);
	if (pos.x + 1 < e->size_map.x && e->map[pos.y][pos.x + 1] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && pos.x + 1 < e->size_map.x &&
			e->map[pos.y + 1][pos.x + 1] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && e->map[pos.y + 1][pos.x] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && pos.x - 1 > 0 &&
			e->map[pos.y + 1][pos.x - 1] == '.')
		return (1);
	if (pos.x - 1 > 0 && e->map[pos.y][pos.x - 1] == '.')
		return (1);
	p->valid = 0;
	e->nb_me--;
	return (0);
}

void			test_valid_point_me(t_e *e)
{
	t_coor_piece	*tmp;

	tmp = e->coor_me;
	while (tmp)
	{
		if (tmp->valid)
		{
			check_valid(e, tmp->pos, tmp);
		}
		tmp = tmp->next;
	}
}
