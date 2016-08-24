/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 07:42:54 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:52:52 by ajubert          ###   ########.fr       */
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
			x++;
		}
		y++;
	}
}
