/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_bloc_en.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:55:25 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 00:28:55 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	mem_bloc_en(t_e *e, int y, int x)
{
/*	if (y <= e->en_hg.pos.y || x <= e->en_hg.pos.x)
	{
		e->en_hg.pos.y = y;
		e->en_hg.pos.x = x;
	}
	if (y <= e->en_hd.pos.y || x >= e->en_hd.pos.x)
	{
		e->en_hd.pos.y = y;
		e->en_hd.pos.x = x;
	}
	if (y >= e->en_bg.pos.y || x <= e->en_bg.pos.x)
	{
		e->en_bg.pos.y = y;
		e->en_bg.pos.x = x;
	}
	if (y >= e->en_bd.pos.y || x >= e->en_bd.pos.x)
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
		e->en_bd.nb++;*/
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
}
