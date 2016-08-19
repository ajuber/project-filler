/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_gauche.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:33:56 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/20 00:35:11 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_gauche(t_e *e)
{
	e->inc1 = 1;
	e->inc2 = 1;
	e->pos_circle1.x = e->en_droit.x + e->inc1;
	e->pos_circle2.x = e->pos_circle1.x;
	e->pos_circle1.y = 0;
	e->pos_circle2.y = e->size_map.y - 1;
}
