/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist_to_center.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 04:13:19 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:36:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		new_dist_to_center(t_e *e)
{
	int				dist;
	int				j;
	t_pos			pos_in_map;
	t_coor_piece	*tmp;

	tmp = e->coor_piece;
	j = 0;
	while (j < e->nb_point)
	{
		if (tmp != e->repere)
		{
			pos_in_map = ft_pos_in_map(e->me_pos, e->repere->pos, tmp->pos);
			dist = calc_dist_to_center(e, pos_in_map);
			if (dist < e->dist_center_me)
			{
				return (1);
			}
		}
		tmp = tmp->next;
		j++;
	}
	return (0);
}
