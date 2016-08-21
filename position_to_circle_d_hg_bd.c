/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_d_hg_bd.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:49:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/21 09:00:48 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_d_hg_bd(t_e *e)
{
	if (e->dir_haut)
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.x = e->en_hg.pos.x + e->inc1;
		e->pos_circle1.y = 0;
/*		if (e->pos_circle1.x == -1)
		{
			e->inc1 = 1;
			e->pos_circle1.x = 0;
			e->pos_circle1.y = e->en_bg.pos.y + e->inc1;
		}*/
		e->pos_circle2.x = e->en_bg.pos.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
/*		if (e->pos_circle2.x < 0)
		{
			e->pos_circle2.y = e->en_bg.pos.y + e->inc2;
			e->pos_circle2.x = 0;
		}*/
	}
	else
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.y = e->en_haut.y + e->inc1;
		e->pos_circle1.x = 0;
	/*	if (e->pos_circle1.y < 0)
		{
			e->inc1 = 1;
			e->pos_circle1.y = 0;
			e->pos_circle1.x = e->en_hd.pos.x + e->inc1;
		}*/
		e->pos_circle2.y = e->en_hd.pos.y + e->inc2;
		e->pos_circle2.x = e->size_map.x - 1;
/*		if (e->pos_circle2.y < 0)
		{
			e->pos_circle2.y = 0;
			e->pos_circle2.x = e->en_hg.pos.x + e->inc2;
		}*/
	}
}
