/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_coord.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 04:37:55 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 12:04:48 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_coord(t_e *e)
{
	t_pos zero;

	zero.x = 0;
	zero.y = 0;
	e->pos_piece = ft_pos_in_map(e->me_pos, e->repere->pos, zero);
//	ft_printf_fd(e->fd1, "pos_piece.y : %d    pos_piece.x : %d", e->pos_piece.y, e->pos_piece.x);
}
