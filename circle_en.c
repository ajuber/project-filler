/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   circle_en.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 02:23:46 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 02:50:48 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		circle_en(t_e *e)
{
	int static c = 0;

	if (c == 0)
		position_to_circle(e);
//	else
//		verif_position_to_circle(e);
	c++;
	move_to_circle(e, e->pos_circle1);
	return (0);
}
