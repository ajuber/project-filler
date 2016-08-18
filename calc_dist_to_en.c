/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_to_en.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 22:24:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/17 22:27:44 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calc_dist_to_en(t_e *e, t_pos var)
{
	t_pos diff;
	int distance;
	t_pos en;
	t_coor_piece *tmp;

	tmp = e->coor_en;
	while (tmp->next)
		tmp = tmp->next;
	en = tmp->pos;
	diff.x = en.x - var.x;
	if (diff.x < 0)
		diff.x *= -1;
	diff.y = en.y - var.y;
	if (diff.y < 0)
		diff.y *= -1;
	distance = diff.x + diff.y;
//	if (0 > (distance = ((var.y + var.x) - (e->center.y + e->center.x))))
//		distance *= -1;
	return (distance);
}
