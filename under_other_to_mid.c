/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   under_other_to_mid.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/25 14:13:03 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 14:18:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		under_other_to_mid(t_e *e, int *dist_min, int dist)
{
	int dist_tmp;

	dist_tmp = dist;
	*dist_min = dist;
	e->tmp = e->coor_me;
	while (e->tmp && e->tmp->valid == 0)
		e->tmp = e->tmp->next;
	while (e->tmp && dist_tmp <= dist)
	{
		dist_tmp = calc_dist_to_center(e, e->tmp->pos);
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
