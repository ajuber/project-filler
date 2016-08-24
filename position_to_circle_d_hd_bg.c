/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_d_hd_bg.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 01:35:16 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:50:23 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		next(t_e *e, int *test)
{
	if (e->cote == 3 && *test)
	{
		ft_swap_int(&e->valid_circle1, &e->valid_circle2);
		*test = 0;
	}
	e->inc1 = -1;
	e->inc2 = -1;
	e->pos_circle1.x = e->hd.g.x + e->inc1;
	e->pos_circle1.y = 0;
	e->pos_circle2.x = e->bg.g.x + e->inc2;
	e->pos_circle2.y = e->size_map.y - 1;
}

void			position_to_circle_d_hd_bg(t_e *e)
{
	static int test = 1;

	e->diagonale = 2;
	if (e->dir_haut)
	{
		if (e->cote == 4 && test)
		{
			ft_swap_int(&e->valid_circle1, &e->valid_circle2);
			test = 0;
		}
		e->inc1 = 1;
		e->inc2 = 1;
		e->pos_circle1.y = e->bg.b.y + e->inc1;
		e->pos_circle1.x = 0;
		e->pos_circle2.y = e->hd.b.y + e->inc2;
		e->pos_circle2.x = e->size_map.x - 1;
	}
	else
		next(e, &test);
}
