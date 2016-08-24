/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_bas.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:32:28 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:38:21 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_bas(t_e *e)
{
	static int test = 1;

	e->cote = 3;
	if (e->en_bloc == 4 && test)
	{
		ft_swap_int(&e->valid_circle1, &e->valid_circle2);
		test = 0;
	}
	e->inc1 = -1;
	e->inc2 = -1;
	e->pos_circle1.y = e->bg.h.y + e->inc1;
	e->pos_circle2.y = e->bd.h.y + e->inc2;
	e->pos_circle1.x = 0;
	e->pos_circle2.x = e->size_map.x - 1;
}
