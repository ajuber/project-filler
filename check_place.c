/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 21:23:35 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/17 00:40:59 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_no_place(t_e *e, t_coor_piece *repere, t_coor_piece *tmp)
{
	t_pos pos_in_map;
//	t_pos diff;

/*	diff.x = tmp->pos.x - repere->pos.x;
	diff.y = tmp->pos.y - repere->pos.y;
	pos_in_map.x = e->me_pos.x + diff.x;
	pos_in_map.y = e->me_pos.y + diff.y;*/
	pos_in_map = ft_pos_in_map(e->me_pos, repere->pos, tmp->pos);
	if (pos_in_map.x >= e->size_map.x || pos_in_map.x < 0 || pos_in_map.y >= e->size_map.y || pos_in_map.y < 0)
		return (1);
	return (0);
}

static int		check_no_point(t_e *e, t_coor_piece *repere, t_coor_piece *tmp)
{
	t_pos pos_in_map;
//	t_pos diff;

/*	diff.x = tmp->pos.x - repere->pos.x;
	diff.y = tmp->pos.y - repere->pos.y;
	pos_in_map.x = e->me_pos.x + diff.x;
	pos_in_map.y = e->me_pos.y + diff.y;*/
	pos_in_map = ft_pos_in_map(e->me_pos, repere->pos, tmp->pos);
	if (e->map[pos_in_map.y][pos_in_map.x] != '.')
		return (1);
	return (0);
}

int				check_place(t_e *e, int j)
{
	int k;
	t_coor_piece *tmp;

	k = 0;
	tmp = e->coor_piece;
	while (k < j)
	{
		tmp = tmp->next;
		k++;
	}
	e->repere = tmp;
	k = 0;
	tmp = e->coor_piece;
	while (k < e->nb_point)
	{
		if (tmp != e->repere && (check_no_place(e, e->repere, tmp) || check_no_point(e, e->repere, tmp)))
			return (0);
		k++;
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (check_no_place(e, e->repere, tmp))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
