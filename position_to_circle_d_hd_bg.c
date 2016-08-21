/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_d_hd_bg.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 01:35:16 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/21 09:00:12 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_d_hd_bg(t_e *e)
{
	if (e->dir_haut)
	{
		e->inc1 = 1;
		e->inc2 = 1;
		e->pos_circle1.y = e->en_bas.y + e->inc1;
		e->pos_circle1.x = 0;
/*		if (e->pos_circle1.y >= e->size_map.y)
		{
			e->pos_circle1.y = e->size_map.y - 1;
			e->pos_circle1.x = e->en_bas.x + e->inc1;
		}*/
		e->pos_circle2.y = e->en_bd.pos.y + e->inc2;
		e->pos_circle2.x = e->size_map.x - 1;
/*		if (e->pos_circle2.y >= e->size_map.y)
		{
			e->inc2 = -1;
			e->pos_circle2.y = e->size_map.y - 1;
			e->pos_circle2.x = e->en_bas.x + e->inc2;
		}*/
	}
	else
	{
		e->inc1 = -1;
		e->inc2 = -1;
		e->pos_circle1.x = e->en_hg.pos.x + e->inc1;
		e->pos_circle1.y = 0;
/*		if (e->pos_circle1.x < 0)
		{
			e->pos_circle1.x = 0;
			e->pos_circle1.y = */
		e->pos_circle2.x = e->en_bg.pos.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
	}
}
