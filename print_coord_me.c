/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord_me.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:47:07 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 02:49:34 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coord_me(t_e *e)
{
	t_coor_piece *tmp;

	ft_printf_fd(e->fd1, "liste coor_me\n");
	tmp = e->coor_me;
	while (tmp)
	{
		ft_printf_fd(e->fd1, "y : %d      x : %d      valid : %d\n", tmp->pos.y, tmp->pos.x, tmp->valid);
		tmp = tmp->next;
	}
}
