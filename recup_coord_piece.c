/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coord_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:25:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 12:00:53 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	recup_coord_piece(t_e *e)
{
	int j;

	e->i = 0;
	e->nb_point = 0;
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant premier while\n");
	while (e->i < e->size_piece.y)
	{
		j = 0;
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant 2e while\n");
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == '*')
			{
				e->nb_point++;
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant push_back_coor\n");
				e->coor_piece = push_back_coor(e->coor_piece, '*', e->i, j);
			}
			j++;
		}
		e->i++;
	}
	e->i = 0;
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant 3e while\n");
	while (e->i < e->size_piece.y)
	{
		j = 0;
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant 4e while\n");
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == '.')
			{
//	ft_printf_fd(e->fd, "dans recup_coord_piece avant 2e push_back_coor\n");
				e->coor_piece = push_back_coor(e->coor_piece, '.', e->i, j);
			}
			j++;
		}
		e->i++;
	}
}
