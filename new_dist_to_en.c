/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_dist_to_en.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 23:14:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:40:30 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		new_dist_to_en(t_e *e)
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
			if (dist < e->dist_me_en)
			{
				return (1);
			}
		}
		tmp = tmp->next;
		j++;
	}
	return (0);
}
