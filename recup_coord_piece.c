/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_coord_piece.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 00:25:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 09:56:12 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		next(t_e *e)
{
	int j;

	e->i = 0;
	while (e->i < e->size_piece.y)
	{
		j = 0;
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == '.')
			{
				e->coor_piece = push_back_coor(e->coor_piece, '.', e->i, j);
			}
			j++;
		}
		e->i++;
	}
}

void			recup_coord_piece(t_e *e)
{
	int j;

	e->i = 0;
	e->nb_point = 0;
	while (e->i < e->size_piece.y)
	{
		j = 0;
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == '*')
			{
				e->nb_point++;
				e->coor_piece = push_back_coor(e->coor_piece, '*', e->i, j);
			}
			j++;
		}
		e->i++;
	}
	next(e);
}
