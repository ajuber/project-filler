/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_to_center.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 23:52:26 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/15 09:39:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calc_dist_to_center(t_e *e, t_pos var)
{
	t_pos diff;
	int distance;

	diff.x = e->center.x - var.x;
	if (diff.x < 0)
		diff.x *= -1;
	diff.y = e->center.y - var.y;
	if (diff.y < 0)
		diff.y *= -1;
	distance = diff.x + diff.y;
//	if (0 > (distance = ((var.y + var.x) - (e->center.y + e->center.x))))
//		distance *= -1;
	return (distance);
}
