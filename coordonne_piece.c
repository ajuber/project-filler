/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordonne_piece.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 04:03:27 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/09 04:54:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	coordonne_piece(t_e *e)
{
	int j;

	e->i = 0;
	while (e->i < e->size_piece.y)
	{
		j = 0;
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == e->me)
				push_back_coor(e->coor_piece, e->i, j);
			j++;
		}
		e->i++;
	}
	e->i = 0;
	while (e->i < e->size_piece.y)
	{
		j = 0;
		while (j < e->size_piece.x)
		{
			if (e->piece[e->i][j] == e->ennemy)
				push_back_coor(e->coor_piece, e->i, j);
			j++;
		}
		e->i++;
	}
}
