/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord_en.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 23:31:29 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/17 23:32:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coord_en(t_e *e)
{
	t_coor_piece *tmp;

	ft_printf_fd(e->fd1, "liste coor_en\n");
	tmp = e->coor_en;
	while (tmp)
	{
		ft_printf_fd(e->fd1, "y : %d      x : %d\n", tmp->pos.y, tmp->pos.x);
		tmp = tmp->next;
	}
}
