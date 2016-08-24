/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_place.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 21:23:35 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:13:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_no_place(t_e *e, t_coor_piece *repere, t_coor_piece *tmp)
{
	t_pos pos_in_map;

	pos_in_map = ft_pos_in_map(e->me_pos, repere->pos, tmp->pos);
	if (pos_in_map.x >= e->size_map.x || pos_in_map.x < 0 ||
			pos_in_map.y >= e->size_map.y || pos_in_map.y < 0)
		return (1);
	return (0);
}

static int		check_no_point(t_e *e, t_coor_piece *repere, t_coor_piece *tmp)
{
	t_pos pos_in_map;

	pos_in_map = ft_pos_in_map(e->me_pos, repere->pos, tmp->pos);
	if (e->map[pos_in_map.y][pos_in_map.x] != '.')
		return (1);
	return (0);
}

static int		check_me(t_e *e)
{
	if (e->map[e->me_pos.y][e->me_pos.x] == e->me)
		return (0);
	return (1);
}

static int		calc(t_e *e, t_coor_piece **tmp)
{
	if (tmp[0] == e->repere && (check_me(e)))
		return (0);
	if (tmp[0] != e->repere && (check_no_place(e, e->repere, tmp[0]) ||
				check_no_point(e, e->repere, tmp[0])))
		return (0);
	tmp[0] = tmp[0]->next;
	return (1);
}

int				check_place(t_e *e, int j)
{
	int				k;
	t_coor_piece	*tmp;

	k = -1;
	tmp = e->coor_piece;
	while (++k < j)
		tmp = tmp->next;
	e->repere = tmp;
	k = -1;
	tmp = e->coor_piece;
	while (++k < e->nb_point)
	{
		if (!calc(e, &tmp))
			return (0);
	}
	while (tmp)
	{
		if (check_no_place(e, e->repere, tmp))
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
