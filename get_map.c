/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:56:00 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 13:02:34 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int	under(t_e *e)
{
	int j;

	j = 0;
	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strcmp(e->map[j], &e->line[4]))
		{
			new_coord(e, e->map[j], &e->line[4], j);
			e->map[j] = ft_strcpy(e->map[j], &e->line[4]);
		}
		j++;
		if (j == e->size_map.y)
		{
			if (e->nb_en_new == e->nb_en)
				e->strat = 3;
			else
				e->nb_en = e->nb_en_new;
			free_line(&e->line);
			return (1);
		}
		free_line(&e->line);
	}
	return (2);
}

int			get_map(t_e *e)
{
	int j;

	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strstr(e->line, "Plateau"))
		{
			free_line(&e->line);
			get_next_line(0, &e->line);
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
