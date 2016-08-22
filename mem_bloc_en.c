/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bloc_en.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:55:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/22 05:31:49 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mem_bloc_en(t_e *e, int y, int x)
{
	if (y <= e->en_hg.pos.y && x <= e->en_hg.pos.x)
	{
		e->en_hg.pos.y = y;
		e->en_hg.pos.x = x;
	}
	if (y <= e->en_hd.pos.y && x >= e->en_hd.pos.x)
	{
		e->en_hd.pos.y = y;
		e->en_hd.pos.x = x;
	}
	if (y >= e->en_bg.pos.y && x <= e->en_bg.pos.x)
	{
		e->en_bg.pos.y = y;
		e->en_bg.pos.x = x;
	}
	if (y >= e->en_bd.pos.y && x >= e->en_bd.pos.x)
	{
		e->en_bd.pos.y = y;
		e->en_bd.pos.x = x;
	}
	if (y <= e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_hg.nb++;
	if (y <= e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_hd.nb++;
	if (y > e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_bg.nb++;
	if (y > e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_bd.nb++;
	if (y < e->en_haut.y)
	{
		e->en_haut.y = y;
		e->en_haut.x = x;
	}
	if (y > e->en_bas.y)
	{
		e->en_bas.y = y;
		e->en_bas.x = y;
	}
	if (x < e->en_gauche.x)
	{
		e->en_gauche.y = y;
		e->en_gauche.x = x;
	}
	if (x > e->en_droit.x)
	{
		e->en_droit.y = y;
		e->en_droit.x = x;
	}
	if (y <= e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_last_bloc = 1;
	if (y <= e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_last_bloc = 2;
	if (y > e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_last_bloc = 3;
	if (y > e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_last_bloc = 4;
	if ((e->cote == 1 && e->en_last_bloc == 3) || (e->cote == 4 && e->en_last_bloc == 2))
	{
		e->diagonale = 2;
		e->dir_haut = 1;
	}
	if ((e->cote == 2 && e->en_last_bloc == 3) || (e->cote == 3 && e->en_last_bloc == 2))
	{
		e->diagonale = 2;
		e->dir_bas = 1;
	}
	if ((e->cote == 1 && e->en_last_bloc == 4) || (e->cote == 2 && e->en_last_bloc == 1))
	{
		e->diagonale = 1;
		e->dir_haut = 1;
	}
	if ((e->cote == 3 && e->en_last_bloc == 1) || (e->cote == 4 && e->en_last_bloc == 4))
	{
		e->diagonale = 1;
		e->dir_bas = 1;
	}
	if (e->en_last_bloc != e->en_bloc && e->dir_haut == 0 && e->dir_bas == 0)
	{
		if (e->en_last_bloc == 1 || e->en_last_bloc == 2)
			e->dir_haut = 1;
		else
			e->dir_bas = 1;
	}
}
