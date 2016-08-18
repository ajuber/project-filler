/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place_to_mid.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 03:57:33 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/11 15:29:19 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	place_to_mid(t_e *e)
{
	t_coor_piece *ind;
	t_coor_piece *temp;
	int				dist_center;
	int				tmp;

	dist_center = e->dist_center_me;
	e->i = 0;
	ind = NULL;
	while (temp != NULL)
	{
		if (check_place() && (tmp = new_dist_mid() <= dist_center))
		{
			ind = temp;
			dist_center = tmp;
		}
		temp = temp->next;
	}
	if (ind != NULL)
	{
		affiche_result();
		return ;
	}
	place_to_mid2(e);
}
