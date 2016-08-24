/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_d_hg_bd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:49:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 04:30:45 by ajubert          ###   ########.fr       */
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
	/*	if (e->pos_circle1.x == -1)
		{
			e->inc1 = 1;
			e->pos_circle1.x = 0;
			e->pos_circle1.y = e->hg.b.y + e->inc1;
		}*/
		e->pos_circle2.x = e->bd.g.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
		/*if (e->pos_circle2.x <= e->size_map.x / 2)
		{
			e->pos_circle2.y = e->bg.pos.y + e->inc2;
			e->pos_circle2.x = 0;
		}*/
	}
	else
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.y = e->hg.h.y + e->inc1;
		e->pos_circle1.x = 0;
	/*	if (e->pos_circle1.y < 0)
		{
			e->inc1 = 1;
			e->pos_circle1.y = 0;
			e->pos_circle1.x = e->en_hd.pos.x + e->inc1;
		}*/
		e->pos_circle2.y = e->bd.h.y + e->inc2;
		e->pos_circle2.x = e->size_map.x - 1;
/*		if (e->pos_circle2.y < 0)
		{
			e->pos_circle2.y = 0;
			e->pos_circle2.x = e->en_hg.pos.x + e->inc2;
		}*/
	}
}
