/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_haut.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:15:14 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 09:34:38 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_haut(t_e *e)
{
	if (e->en_bloc == 1)
		ft_swap_int(&e->valid_circle1, &e->valid_circle2);
	e->inc1 = 1;
	e->inc2 = 1;
	e->pos_circle1.y = e->en_bg.pos.y + e->inc1;
	e->pos_circle2.y = e->en_bd.pos.y + e->inc2;
	e->pos_circle1.x = 0;
	e->pos_circle2.x = e->size_map.x - 1;
}
