/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_circle.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/19 01:13:57 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:07:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		move_to_circle(t_e *e, t_pos cir)
{
	t_coor_piece	*tmp;
	int				j;

	e->dist_center_me = -1;
	e->i = -1;
	tmp = e->coor_me;
	while (++e->i < e->nb_me)
	{
		j = 0;
		if (!(search_point_to(e, e->dist_center_me, cir)))
			return (0);
		e->dist_center_me = calc_dist_to(cir, e->me_pos);
		while (j < e->nb_point)
		{
			if (check_place(e, j) && (new_dist_to(e, cir)))
			{
				print_coord(e);
				mem_coord_me(e);
				return (1);
			}
			j++;
		}
		tmp = tmp->next;
	}
	return (0);
}
