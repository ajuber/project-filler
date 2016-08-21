/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_gauche.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:33:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/21 06:09:57 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_gauche(t_e *e)
{
	e->inc1 = 1;
	e->inc2 = 1;
	e->pos_circle1.x = e->en_hd.pos.x + e->inc1;
	e->pos_circle2.x = e->en_bd.pos.x + e->inc2;
	e->pos_circle1.y = 0;
	e->pos_circle2.y = e->size_map.y - 1;
}
