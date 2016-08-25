/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:52:24 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 10:44:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "filler.h"

static int		calc1(t_e *e)
{
	int result;

	result = 0;
	if (e->strat == 0)
	{
		result = move_to_mid(e);
		if (result == 0 && !move_to_en(e) && !move_to_random(e))
		{
			fin_filler(e);
			return (0);
		}
	}
	if (result == 2)
	{
		result = -1;
		e->strat = 1;
	}
	if (e->strat == 1 && !circle_en(e) && !move_to_en(e) && !move_to_random(e))
	{
		fin_filler(e);
		return (0);
	}
	return (1);
}

static int		calc2(t_e *e)
{
	if (e->strat == 2 && move_to_en(e) == 0 && move_to_random(e) == 0)
	{
		fin_filler(e);
		return (0);
	}
	if (e->strat == 3 && move_to_random(e) == 0)
	{
		fin_filler(e);
		return (0);
	}
	return (1);
}

static int		calc(t_e *e)
{
	if (!get_piece(e))
		return (0);
	recup_coord_piece(e);
	if (!calc1(e))
		return (0);
	if (!calc2(e))
		return (0);
	ft_printf("%d %d\n", e->pos_piece.y, e->pos_piece.x);
	free_piece(e->piece, e->size_piece.y);
//	e->coor_piece = NULL;
	ft_free_list_coor(&e->coor_piece);
	return (1);
}

int				main(void)
{
	t_e		e;

	ft_bzero(&e, sizeof(t_e));
	e.fd1 = open("test", O_CREAT | O_RDWR | O_APPEND, 0640);
	search_char(&e);
	if (!first_map(&e))
		return (0);
	if (e.error_map)
	{
		fin_filler(&e);
		return (0);
	}
	first_pos(&e);
	if (!calc(&e))
		return (0);
	while (get_map(&e))
	{
		test_valid_point_me(&e);
		if (!calc(&e))
			return (0);
	}
	free_map(e.map, e.size_map.y);
	return (0);
}
