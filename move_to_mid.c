/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_mid.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 21:52:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:29:21 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	calc(t_e *e, int j)
{
	if (check_place(e, j) && new_dist_to_center(e))
	{
		print_coord(e);
		mem_coord_me(e);
		return (1);
	}
	return (0);
}

int			move_to_mid(t_e *e)
{
	t_coor_piece	*tmp;
	int				j;

	e->dist_center_me = -1;
	e->i = -1;
	tmp = e->coor_me;
	while (++e->i < e->nb_me)
	{
		j = 0;
		if (!(search_point_to_mid(e, e->dist_center_me)))
			return (0);
		e->dist_center_me = calc_dist_to_center(e, e->me_pos);
		if (e->dist_center_me < 3)
			return (2);
		while (j < e->nb_point)
		{
			if (calc(e, j))
				return (1);
			j++;
		}
		tmp = tmp->next;
	}
	return (0);
}
