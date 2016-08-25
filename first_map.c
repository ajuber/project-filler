/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:56:00 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:39:02 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "filler.h"

int		first_map(t_e *e)
{
	int j;

	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strstr(e->line, "Plateau"))
		{
			if (!recup_size_tab(e, e->line))
				return (0);
			free_line(&e->line);
			get_next_line(0, &e->line);
			free_line(&e->line);
			j = 0;
			while (get_next_line(0, &e->line) > 0)
			{
				if (!recup_tab(e, j, e->line))
					return (0);
				j++;
				if (j == e->size_map.y)
				{
					ft_error_map(e);
					free_line(&e->line);
					return (1);
				}
				free_line(&e->line);
			}
		}
		free_line(&e->line);
	}
	free_line(&e->line);
	return (0);
}
