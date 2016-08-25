/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:00:07 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 13:02:43 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	under(t_e *e)
{
	int j;

	j = 0;
	while (get_next_line(0, &e->line) > 0)
	{
		if (!recup_piece(e, j, e->line))
			return (0);
		j++;
		if (j == e->size_piece.y)
		{
			free_line(&e->line);
			return (1);
		}
		free_line(&e->line);
	}
	return (2);
}

int			get_piece(t_e *e)
{
	int j;

	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strstr(e->line, "Piece"))
		{
			if (!recup_size_piece(e, e->line))
				return (0);
			free_line(&e->line);
			if (!(j = under(e)))
				return (0);
			if (j == 1)
				return (1);
		}
		free_line(&e->line);
	}
	free_line(&e->line);
	return (0);
}
