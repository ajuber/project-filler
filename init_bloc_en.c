/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bloc_en.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:57:59 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:54:39 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_bloc_en(t_e *e, int y, int x)
{
	if (y <= e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_bloc = 1;
	if (y <= e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_bloc = 2;
	if (y > e->size_map.y / 2 && x <= e->size_map.x / 2)
		e->en_bloc = 3;
	if (y > e->size_map.y / 2 && x > e->size_map.x / 2)
		e->en_bloc = 4;
	e->en_last_bloc = e->en_bloc;
	init_card(e);
	if (e->en_bloc == 1)
		e->hg = init_pos_card(y, x);
	if (e->en_bloc == 2)
		e->hd = init_pos_card(y, x);
	if (e->en_bloc == 3)
		e->bg = init_pos_card(y, x);
	if (e->en_bloc == 4)
		e->bd = init_pos_card(y, x);
}
