/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_char.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 16:04:38 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 07:34:46 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	search_char(t_e *e)
{
	int order;

	e->i = 0;
	get_next_line(0, &e->line);
	if (e->line[0] == '$')
	{
		while (!(ft_isdigit(e->line[e->i])))
			e->i++;
		order = e->line[e->i] - '0';
		if (order == 1)
		{
			e->me = 'O';
			e->en = 'X';
		}
		else
		{
			e->me = 'X';
			e->en = 'O';
		}
	}
	free_line(e->line);
}
