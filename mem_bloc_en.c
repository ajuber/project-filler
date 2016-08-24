/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bloc_en.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:55:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:32:41 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		first(t_e *e, int y, int x)
{
	if (y <= e->size_map.y / 2 && x <= e->size_map.x / 2)
	{
		e->hg = new_card(e->hg, y, x);
		e->en_last_bloc = 1;
	}
	if (y <= e->size_map.y / 2 && x > e->size_map.x / 2)
	{
		e->hd = new_card(e->hd, y, x);
		e->en_last_bloc = 2;
	}
	if (y > e->size_map.y / 2 && x <= e->size_map.x / 2)
	{
		e->bg = new_card(e->bg, y, x);
		e->en_last_bloc = 3;
	}
	if (y > e->size_map.y / 2 && x > e->size_map.x / 2)
	{
		e->bd = new_card(e->bd, y, x);
		e->en_last_bloc = 4;
	}
}

static void		second(t_e *e)
{
	if ((e->cote == 1 && e->en_last_bloc == 3) ||
			(e->cote == 4 && e->en_last_bloc == 2))
	{
		e->diagonale = 2;
		e->dir_haut = 1;
	}
	if ((e->cote == 2 && e->en_last_bloc == 3) ||
			(e->cote == 3 && e->en_last_bloc == 2))
	{
		e->diagonale = 2;
		e->dir_bas = 1;
	}
	if ((e->cote == 1 && e->en_last_bloc == 4) ||
			(e->cote == 2 && e->en_last_bloc == 1))
	{
		e->diagonale = 1;
		e->dir_haut = 1;
	}
	if ((e->cote == 3 && e->en_last_bloc == 1) ||
			(e->cote == 4 && e->en_last_bloc == 4))
	{
		e->diagonale = 1;
		e->dir_bas = 1;
	}
}

void			mem_bloc_en(t_e *e, int y, int x)
{
	first(e, y, x);
	second(e);
	if (e->en_last_bloc != e->en_bloc && e->dir_haut == 0 && e->dir_bas == 0)
	{
		if (e->en_last_bloc == 1 || e->en_last_bloc == 2)
			e->dir_haut = 1;
		else
			e->dir_bas = 1;
	}
}
