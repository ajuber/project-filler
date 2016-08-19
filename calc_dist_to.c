/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist_to.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:48:13 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 01:49:25 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		calc_dist_to(t_pos var, t_pos var1)
{
	t_pos diff;
	int distance;

	diff.x = var1.x - var.x;
	if (diff.x < 0)
		diff.x *= -1;
	diff.y = var1.y - var.y;
	if (diff.y < 0)
		diff.y *= -1;
	distance = diff.x + diff.y;
//	if (0 > (distance = ((var.y + var.x) - (e->center.y + e->center.x))))
//		distance *= -1;
	return (distance);
}
