/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_to_circle_haut.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 00:15:14 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/20 00:31:31 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	position_to_circle_haut(t_e *e)
{
	e->inc1 = 1;
	e->inc2 = 1;
	e->pos_circle1.y = e->en_bas.y + e->inc1;
	e->pos_circle2.y = e->pos_circle1.y;
	e->pos_circle1.x = 0;
	e->pos_circle2.x = e->size_map.x - 1;
}
