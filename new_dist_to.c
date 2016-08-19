/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist_to.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 02:55:47 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 04:43:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		new_dist_to(t_e *e, t_pos cir)
{
	int dist;
	int j;
	t_pos pos_in_map;
	t_coor_piece *tmp;

	tmp = e->coor_piece;
	j = 0;
	while (j < e->nb_point)
	{
		if (tmp != e->repere)
		{
			pos_in_map = ft_pos_in_map(e->me_pos, e->repere->pos, tmp->pos);
			dist = calc_dist_to(cir, pos_in_map);
		if (dist < e->dist_center_me)
		{
			return (1);
		}
		}
		tmp = tmp->next;
		j++;
	}
	return (0);
}
