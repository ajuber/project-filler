/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_point_to.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:28:10 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 14:24:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int			under_first(t_e *e, t_coor_piece **tmp)
{
	tmp[0] = e->coor_me;
	while (tmp[0] && tmp[0]->valid == 0)
		tmp[0] = tmp[0]->next;
	if (tmp[0] == NULL)
		return (0);
	e->ind = tmp[0];
	return (1);
}

static int			search_first_point(t_e *e, t_pos cir)
{
	int				dist_tmp;
	int				dist_min;
	int				j;
	t_coor_piece	*tmp;

	j = 1;
	if (!(under_first(e, &tmp)))
		return (0);
	dist_min = calc_dist_to(cir, tmp->pos);
	while (j < e->nb_me)
	{
		tmp = tmp->next;
		while (tmp && tmp->valid == 0)
			tmp = tmp->next;
		dist_tmp = calc_dist_to(cir, tmp->pos);
		if (dist_tmp < dist_min)
		{
			dist_min = dist_tmp;
			e->ind = tmp;
		}
		j++;
	}
	e->me_pos.y = e->ind->pos.y;
	e->me_pos.x = e->ind->pos.x;
	return (1);
}

static int			search_other_point_egal(t_e *e, int dist, t_pos cir)
{
	t_coor_piece	*tmp;
	int				dist_tmp;

	tmp = e->coor_me;
	while (tmp != e->ind)
		tmp = tmp->next;
	tmp = tmp->next;
	while (tmp && tmp->valid == 0)
		tmp = tmp->next;
	while (tmp)
	{
		dist_tmp = calc_dist_to(cir, tmp->pos);
		if (dist_tmp == dist)
		{
			e->ind = tmp;
			e->me_pos.y = e->ind->pos.y;
			e->me_pos.x = e->ind->pos.x;
			return (1);
		}
		tmp = tmp->next;
		while (tmp && tmp->valid == 0)
			tmp = tmp->next;
	}
	return (0);
}

static int			search_other_point(t_e *e, int dist, t_pos cir)
{
	int				dist_tmp;
	int				dist_min;

	dist_tmp = under_other_to(e, cir, &dist_min, dist);
	while (e->tmp)
	{
		dist_tmp = calc_dist_to(cir, e->tmp->pos);
		if (dist_tmp < dist_min && dist_tmp > dist)
		{
			dist_min = dist_tmp;
			e->ind = e->tmp;
		}
		e->tmp = e->tmp->next;
		while (e->tmp && e->tmp->valid == 0)
			e->tmp = e->tmp->next;
	}
	if (dist_min != dist)
	{
		e->me_pos.y = e->ind->pos.y;
		e->me_pos.x = e->ind->pos.x;
		return (1);
	}
	return (0);
}

int					search_point_to(t_e *e, int dist, t_pos cir)
{
	if (dist == -1)
	{
		if (search_first_point(e, cir))
			return (1);
		return (0);
	}
	if (search_other_point_egal(e, dist, cir))
		return (1);
	if (search_other_point(e, dist, cir))
		return (1);
	return (0);
}
