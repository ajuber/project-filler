/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_en.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:23:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/20 00:59:54 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		circle_en(t_e *e)
{
//	int static c = 0;
	t_coor_piece *tmp;
	int				dist_to_circle1;
	int				dist_to_circle2;
//	if (c == 0)
		position_to_circle(e);
//	else
//		verif_position_to_circle(e);
//	c++;
	tmp = e->coor_en;
	while (tmp->next)
		tmp = tmp->next;
	dist_to_circle1 = calc_dist_to(e->pos_circle1, tmp->pos);
	dist_to_circle2 = calc_dist_to(e->pos_circle2, tmp->pos);
	if (dist_to_circle1 <= dist_to_circle2)
		move_to_circle(e, e->pos_circle1);
	else
		move_to_circle(e, e->pos_circle2);
	return (0);
}
