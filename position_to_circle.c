/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 05:44:43 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 09:42:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle(t_e *e)
{
	/*if (e->en_hd.nb == 0 && e->en_bg.nb == 0 && e->en_bd.nb == 0)
	{
		e->pos_circle1.y = 0;
		if (e->en_hd.x >= e->en_bd.x)
			e->pos_circle1.x = e->en_hd.x + 1;
		else
			e->pos_circle1.x = e->en_bd.x + 1;
		e->pos_circle2.x = 0;
		if (e->en_bg.y >= e->en_bd.y)
			e->pos_circle2.y = e->en_bg.y + 1;
		else
			e->pos_circle2.y = e->en_bd.y + 1;
	}
	if (e->en_hg.nb == 0 && e->en_bg.nb == 0 && e->en_bd.nb == 0)
	{
		e->pos_circle1.y = 0;
		if (e->en_hg.x >= e->en_bg.x)
			e->pos_circle1.x = e->en_hg.x + 1;
		else
			e->pos_circle1.x = e->en_bg.x + 1;
		e->pos_circle2.x = e->size_map.x - 1;
		if (e->en_bg.y >= e->en_bd.y)
			e->pos_circle2.y = e->en_bg.y + 1;
		else
			e->pos_circle2.y = e->en_bd.y + 1;
	}
	if (e->en_hg.nb == 0 && e->en_hd.nb == 0 && e->en_bd.nb == 0)
	{
		e->pos_circle1.x = 0;
		if (e->en_hg.y <= e->en_hd.y)
			e->pos_circle1.y = e->en_hg.y + 1;
		else
			e->pos_circle1.y = e->en_bg.y + 1;
		e->pos_circle2.y = e->size_map.y - 1;
		if (e->en_hd.x >= e->en_bd.x)
			e->pos_circle2.x = e->en_bg.x - 1;
		else
			e->pos_circle2.x = e->en_bd.x - 1;
	}
	if (e->en_hg.nb == 0 && e->en_bg.nb == 0 && e->en_hd.nb == 0)
	{
		e->pos_circle1.y = 0;
		if (e->en_hg.x >= e->en_bg.x)
			e->pos_circle1.x = e->en_hg.x + 1;
		else
			e->pos_circle1.x = e->en_bg.x + 1;
		e->pos_circle2.x = e->size_map.x - 1;
		if (e->en_bg.y >= e->en_bd.y)
			e->pos_circle2.y = e->en_bg.y + 1;
		else
			e->pos_circle2.y = e->en_bd.y + 1;
	}*/
	if (e->en_bloc == e->en_last_bloc)
	{
	if (e->en_bloc == 4)
	{
		e->inc1 = -1;
		e->pos_circle1.y = e->en_haut.y + e->inc1;
		e->pos_circle1.x = e->size_map.x - 1;
	/*	if (e->pos_circle1.y < 0)
		{
			e->pos_circle1.y = 0;
			e->pos_circle1.x = e->en_gauche.x + e->inc1;
		}*/
		e->inc2 = -1;
		e->pos_circle2.x = e->en_gauche.x + e->inc2;
		e->pos_circle2.y = e->size_map.y - 1;
	/*	if (e->pos_circle2.x < 0)
		{
			e->pos_circle2.x = 0;
			e->pos_circle2.y = e->en_haut.y + e->inc2;
		}*/
	}
	if (e->en_bloc == 3)
	{
		e->inc2 = 1;
		e->pos_circle2.y = e->size_map.y - 1;;
		e->pos_circle2.x = e->en_droit.x + e->inc2;
		/*if (e->pos_circle2.x >= e->size_map.x)
		{
			e->inc2 = -1;
			e->pos_circle2.y = e->en_haut.y + e->inc2;
			e->pos_circle2.x = e->size_map.x - 1;
		}*/
		e->inc1 = -1;
		e->pos_circle1.x = 0;
		e->pos_circle1.y = e->en_haut.y + e->inc1;
		/*if (e->pos_circle1.y < 0)
		{
			e->inc1 = 1;
			e->pos_circle1.x = e->en_droit.x + e->inc1;
			e->pos_circle1.y = 0;
		}*/
	}
	if (e->en_bloc == 2)
	{
		e->inc1 = -1;
		e->pos_circle1.y = 0;
		e->pos_circle1.x = e->en_gauche.x + e->inc1;
		/*if (e->pos_circle1.x < 0)
		{
			e->inc1 = 1;
			e->pos_circle1.y = e->en_bas.y + e->inc1;
			e->pos_circle1.x = 0;
		}*/
		e->inc2 = 1;
		e->pos_circle2.x = e->size_map.x - 1;
		e->pos_circle2.y = e->en_bas.y + e->inc2;
		/*if (e->pos_circle2.y >= e->size_map.y)
		{
			e->inc2 = -1;
			e->pos_circle2.x = e->en_gauche.x + e->inc2;
			e->pos_circle2.y = e->size_map.y - 1;
		}*/
	}
	if (e->en_bloc == 1)
	{
		e->inc2 = 1;
		e->pos_circle2.y = e->en_bas.y + e->inc2;
		e->pos_circle2.x = 0;
	/*	if (e->pos_circle2.y >= e->size_map.y)
		{
			e->pos_circle2.y = e->size_map.y - 1;
			e->pos_circle2.x = e->en_droit.x + e->inc2;
		}*/
		e->inc1 = 1;
		e->pos_circle1.x = e->en_droit.x + e->inc1;
		e->pos_circle1.y = 0;
	/*	if (e->pos_circle1.x >= e->size_map.x)
		{
			e->pos_circle1.x = e->size_map.x - 1;
			e->pos_circle1.y = e->en_bas.y + e->inc1;
		}*/
	}
	}
	if ((e->en_bloc == 1 && e->en_last_bloc == 2) || (e->en_bloc == 2 && e->en_last_bloc == 1))
		position_to_circle_haut(e);
	if ((e->en_bloc == 1 && e->en_last_bloc == 3) || (e->en_bloc == 3 && e->en_last_bloc == 1))
		position_to_circle_gauche(e);
	if ((e->en_bloc == 2 && e->en_last_bloc == 4) || (e->en_bloc == 4 && e->en_last_bloc == 2))
		position_to_circle_droite(e);
	if ((e->en_bloc == 3 && e->en_last_bloc == 4) || (e->en_bloc == 4 && e->en_last_bloc == 3))
		position_to_circle_bas(e);
	if ((e->en_bloc == 1 && e->en_last_bloc == 4) || (e->en_bloc == 4 && e->en_last_bloc == 1))
		position_to_circle_d_hg_bd(e);
	if ((e->en_bloc == 2 && e->en_last_bloc == 3) || (e->en_bloc == 3 && e->en_last_bloc == 2))
		position_to_circle_d_hd_bg(e);
}
