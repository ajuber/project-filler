/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_en.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:23:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 07:44:20 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		circle_en(t_e *e)
{
	t_coor_piece	*tmp;
	int				dist_to_circle1;
	int				dist_to_circle2;

	position_to_circle(e);
	tmp = e->coor_en;
	while (tmp->next)
		tmp = tmp->next;
	dist_to_circle1 = calc_dist_to(e->pos_circle1, tmp->pos);
	dist_to_circle2 = calc_dist_to(e->pos_circle2, tmp->pos);
	if (e->valid_circle1 != 1 &&
			(e->valid_circle2 || dist_to_circle1 <= dist_to_circle2))
		if (move_to_circle(e, e->pos_circle1) != 0)
			return (1);
	if (e->valid_circle2 != 1 &&
			(e->valid_circle1 || dist_to_circle2 < dist_to_circle1))
		if (move_to_circle(e, e->pos_circle2) != 0)
			return (1);
	return (0);
}
