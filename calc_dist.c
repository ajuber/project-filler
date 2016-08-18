/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_dist.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 21:38:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/07/26 22:25:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	calc_dist(t_e *e)
{
	int j;

	j = 0;
	e->i = 0;
	while (e->i < e->size_map.y)
	{
		while (e->tab[e->i][j] != e->ennemy)
			j++;
		if (e->tab[e->i][j] == e->ennemy)
		{
			e->ennemy_pos.y = e->i;
			e->ennemy_pos.x = j;
		}
		e->i++;
	}
	j = 0;
	e->i = 0;
	while (e->i < e->size_map.y)
	{
		while (e->tab[e->i][j] != e->me)
			j++;
		if (e->tab[e->i][j] == e->me)
		{
			e->me_pos.y = e->i;
			e->me_pos.x = j;
		}
		e->i++;
	}
	if (0 > (e->distance = ((e->ennemy_pos.y + e->ennemy_pos.x) - (e->me_pos.y + e->me_pos.x))))
		e->distance *= -1;
}
