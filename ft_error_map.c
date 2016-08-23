/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 07:42:54 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 07:55:56 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_error_map(t_e *e)
{
	int count_en;
	int count_me;
	int y;
	int x;

	y = 0;
	count_en = 0;
	count_me = 0;
	while (y < e->size_map.y)
	{
		x = 0;
		while (x < e->size_map.x)
		{
			if (!(ft_strchr(".OXx", e->map[y][x])))
			{
				e->error_map = 1;
				return ;
			}
			if (e->map[y][x] == e->me)
				count_me++;
			if (e->map[y][x] == e->en || e->map[y][x] == e->en + 32)
				count_en++;
			x++;
		}
		y++;
	}
	if (count_me != 1)
	{
		e->error_map = 1;
		return ;
	}
	if (e->me == 'O' && count_en != 1)
	{
		e->error_map = 1;
		return ;
	}
}
