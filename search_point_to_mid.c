/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_point_to_mid.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:48:03 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/16 22:35:21 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		search_first_point(t_e *e)
{
	int dist_tmp;
	int dist_min;
	int			j;
	t_coor_piece *tmp;

	j = 1;
		ft_printf_fd(e->fd, "pendant search_first_point avant pointeur\n");
	tmp = e->coor_me;
		ft_printf_fd(e->fd, "pendant search_first_point avant pointeur 2\n");
	e->ind = tmp;
		ft_printf_fd(e->fd, "pendant search_first_point avant calc_dist_to_center\n");
	dist_min = calc_dist_to_center(e, tmp->pos);
	while (j < e->nb_me)
	{
		ft_printf_fd(e->fd, "pendant search_first_point dqns while\n");
		tmp = tmp->next;
		dist_tmp = calc_dist_to_center(e, tmp->pos);
		if (dist_tmp < dist_min)
		{
			dist_min = dist_tmp;
			e->ind = tmp;
		}
		j++;
	}
		ft_printf_fd(e->fd, "pendant search_first_point avant position\n");
	e->me_pos.y = e->ind->pos.y;
	e->me_pos.x = e->ind->pos.x;
}

static int		search_other_point_egal(t_e *e, int dist)
{
	t_coor_piece *tmp;
	int				dist_tmp;

	tmp = e->coor_me;
	while (tmp != e->ind)
		tmp = tmp->next;
	tmp = tmp->next;
	while (tmp)
	{
		dist_tmp = calc_dist_to_center(e, tmp->pos);
		if (dist_tmp == dist)
		{
			e->ind = tmp;
			e->me_pos.y = e->ind->pos.y;
			e->me_pos.x = e->ind->pos.x;
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int		search_other_point(t_e *e, int dist)
{
	t_coor_piece *tmp;
	int				dist_tmp;
	int				dist_min;

	dist_tmp = dist;
	dist_min = dist;
	tmp = e->coor_me;
	while (tmp && dist_tmp <= dist)
	{
		dist_tmp = calc_dist_to_center(e, tmp->pos);
		if (dist_tmp > dist)
		{
			dist_min = dist_tmp;
			e->ind = tmp;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		dist_tmp = calc_dist_to_center(e, tmp->pos);
		if (dist_tmp < dist_min && dist_tmp > dist)
		{
			dist_min = dist_tmp;
			e->ind = tmp;
		}
		tmp = tmp->next;
	}
	if (dist_min != dist)
	{
		e->me_pos.y = e->ind->pos.y;
		e->me_pos.x = e->ind->pos.x;
		return (1);
	}
	return (0);
}

int				search_point_to_mid(t_e *e, int dist)
{
	if (dist == -1)
	{
		ft_printf_fd(e->fd, "pendant search_point_to_mid avant search_first_point\n");
		search_first_point(e);
		ft_printf_fd(e->fd, "pendant search_point_to_mid apres search_first_point\n");
		return (1);
	}
	if (search_other_point_egal(e, dist))
		return (1);
	if (search_other_point(e, dist))
		return (1);
	return (0);
}
