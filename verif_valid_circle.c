/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_valid_circle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 02:19:19 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 10:18:46 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	verif_valid_circle(t_e *e, t_pos var)
{
	int dist_1;
	int dist_2;

	dist_1 = calc_dist_to(var, e->pos_circle1);
	dist_2 = calc_dist_to(var, e->pos_circle2);
	if (dist_1 == 0)
	{
		e->valid_circle1 = 1;
	}
	if (dist_2 == 0)
	{
		e->valid_circle2 = 1;
	}
	if (e->valid_circle1 == 1 && e->valid_circle2 == 1)
		e->strat = 2;
}
