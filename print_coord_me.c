/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord_me.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 07:47:07 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/15 07:53:05 by ajubert          ###   ########.fr       */
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
		ft_printf_fd(e->fd1, "y : %d      x : %d\n", tmp->pos.y, tmp->pos.x);
		tmp = tmp->next;
	}
}
