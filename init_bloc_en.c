/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bloc_en.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:57:59 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 02:51:58 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_bloc_en(t_e *e, int y, int x)
{
	/*e->en_hg.pos.y = y;
	e->en_hg.pos.x = x;
	e->en_hd.pos.y = y;
	e->en_hd.pos.x = x;
	e->en_bg.pos.y = y;
	e->en_bg.pos.x = x;
	e->en_bd.pos.y = y;
	e->en_bd.pos.x = x;
	e->en_hg.nb = 0;
	e->en_hd.nb = 0;
	e->en_bg.nb = 0;
	e->en_bd.nb = 0;*/
	e->en_haut.y = y;
	e->en_haut.x = x;
	e->en_bas.y = y;
	e->en_bas.x = x;
	e->en_gauche.y = y;
	e->en_gauche.x = x;
	e->en_droit.y = y;
	e->en_droit.x = x;
	if (y <= e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_bloc = 1;
	if (y <= e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_bloc = 2;
	if (y > e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_bloc = 3;
	if (y > e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_bloc = 4;
}
