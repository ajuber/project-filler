/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_d_hg_bd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:49:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:41:43 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_d_hg_bd(t_e *e)
{
	e->diagonale = 1;
	if (e->dir_haut)
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.x = e->hg.g.x + e->inc1;
		e->pos_circle1.y = 0;
		e->pos_circle2.x = e->bd.g.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
	}
	else
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.y = e->hg.h.y + e->inc1;
		e->pos_circle1.x = 0;
		e->pos_circle2.y = e->bd.h.y + e->inc2;
		e->pos_circle2.x = e->size_map.x - 1;
	}
}
