/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_other_to.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 13:55:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 13:57:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			under_other_to(t_e *e, t_pos cir, int *dist_min, int dist)
{
	int dist_tmp;

	dist_tmp = dist;
	*dist_min = dist;
	e->tmp = e->coor_me;
	while (e->tmp && e->tmp->valid == 0)
		e->tmp = e->tmp->next;
	while (e->tmp && dist_tmp <= dist)
	{
		dist_tmp = calc_dist_to(cir, e->tmp->pos);
		if (dist_tmp > dist)
		{
			*dist_min = dist_tmp;
			e->ind = e->tmp;
		}
		e->tmp = e->tmp->next;
		while (e->tmp && e->tmp->valid == 0)
			e->tmp = e->tmp->next;
	}
	return (dist_tmp);
}
