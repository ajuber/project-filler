/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_en.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 01:58:49 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/21 04:45:18 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_en(t_e *e)
{
	t_coor_piece *tmp;
	int				j;

	e->dist_me_en = -1;
	e->i = 0;
	tmp = e->coor_me;
	while (e->i < e->nb_me)
	{
		j = 0;
		if (!(search_point_to_en(e, e->dist_me_en)))
			return (0);
		e->dist_me_en = calc_dist_to_en(e, e->me_pos);
		if (e->dist_me_en < 3)
			return (2);
		while (j < e->nb_point)
		{
			if (check_place(e, j))
			{
				if (new_dist_to_en(e))
				{
					print_coord(e);
					mem_coord_me(e);
					print_coord_me(e);
					print_coord_en(e);
					return (1);
				}
			}
			j++;
		}
		tmp = tmp->next;
		e->i++;
	}
	return (0);
}
