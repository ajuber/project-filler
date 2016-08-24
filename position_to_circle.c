/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 05:44:43 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 10:06:51 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		first(t_e *e)
{
	if (e->en_bloc == 4)
	{
		e->inc1 = -1;
		e->pos_circle1.y = e->bd.h.y + e->inc1;
		e->pos_circle1.x = e->size_map.x - 1;
		e->inc2 = -1;
		e->pos_circle2.x = e->bd.g.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
	}
	if (e->en_bloc == 3)
	{
		e->inc2 = 1;
		e->pos_circle2.y = e->size_map.y - 1;
		e->pos_circle2.x = e->bg.d.x + e->inc2;
		e->inc1 = -1;
		e->pos_circle1.x = 0;
		e->pos_circle1.y = e->bg.h.y + e->inc1;
	}
}

static void		second(t_e *e)
{
	if (e->en_bloc == 2)
	{
		e->inc1 = -1;
		e->pos_circle1.y = 0;
		e->pos_circle1.x = e->hd.g.x + e->inc1;
		e->inc2 = 1;
		e->pos_circle2.x = e->size_map.x - 1;
		e->pos_circle2.y = e->hd.b.y + e->inc2;
	}
	if (e->en_bloc == 1)
	{
		e->inc2 = 1;
		e->pos_circle2.y = e->hg.b.y + e->inc2;
		e->pos_circle2.x = 0;
		e->inc1 = 1;
		e->pos_circle1.x = e->hg.d.x + e->inc1;
		e->pos_circle1.y = 0;
	}
}

static void		third(t_e *e)
{
	if (((e->en_bloc == 1 && e->en_last_bloc == 2)
				|| (e->en_bloc == 2 && e->en_last_bloc == 1) || e->cote == 1)
			&& e->diagonale == 0)
		position_to_circle_haut(e);
	if (((e->en_bloc == 1 && e->en_last_bloc == 3)
				|| (e->en_bloc == 3 && e->en_last_bloc == 1) || e->cote == 4)
			&& e->diagonale == 0)
		position_to_circle_gauche(e);
	if (((e->en_bloc == 2 && e->en_last_bloc == 4)
				|| (e->en_bloc == 4 && e->en_last_bloc == 2) || e->cote == 2)
			&& e->diagonale == 0)
		position_to_circle_droite(e);
	if (((e->en_bloc == 3 && e->en_last_bloc == 4)
				|| (e->en_bloc == 4 && e->en_last_bloc == 3) || e->cote == 3)
			&& e->diagonale == 0)
		position_to_circle_bas(e);
	if ((e->en_bloc == 1 && e->en_last_bloc == 4)
			|| (e->en_bloc == 4 && e->en_last_bloc == 1) || e->diagonale == 1)
		position_to_circle_d_hg_bd(e);
	if ((e->en_bloc == 2 && e->en_last_bloc == 3)
			|| (e->en_bloc == 3 && e->en_last_bloc == 2) || e->diagonale == 2)
		position_to_circle_d_hd_bg(e);
}

void			position_to_circle(t_e *e)
{
	if (e->en_bloc == e->en_last_bloc && e->cote == 0 && e->diagonale == 0)
	{
		first(e);
		second(e);
	}
	third(e);
}
