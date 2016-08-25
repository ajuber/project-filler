/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:56:00 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 00:39:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "filler.h"

int		get_map(t_e *e)
{
	int j;
	int fd;
//	int fd1;

	fd = open("output.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
//	fd1 = open("debug.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
//	(void)e;
//	write(1, "8 2", 3);
	e->list = NULL;
	e->line = NULL;
	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strstr(e->line, "Plateau"))
		{
			free_line(&e->line);
			get_next_line(0, &e->line);
			free_line(&e->line);
			j = 0;
			while (get_next_line(0, &e->line) > 0)
			{
				if (ft_strcmp(e->map[j], &e->line[4]))
				{
					new_coord(e, e->map[j], &e->line[4], j);
					e->map[j] = ft_strcpy(e->map[j], &e->line[4]);
				}
				ft_printf_fd(fd, "%s\n", &e->line[4]);
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
		}
		free_line(&e->line);
	}
	free_line(&e->line);
	/*	e->list = push_back_str(e->list, e->line);
		//if (e->line[1] == 'i')
		//	test++;
		ft_printf_fd(fd, "%s\n", e->line);
		while (get_next_line(0, &e->line) > 0)
		{
			e->list = push_back_str(e->list, e->line);
		}
		free(e->line);
	}*/
/*	e->size = count_list_str(e->list);
	if (!(e->tab = (char **)malloc(sizeof(char *) * e->size)))
		return (0);
	e->temp = e->list->next;
	while (e->i < e->size)
	{
		e->tab[e->i] = ft_strdup(e->temp->str);
		e->i++;
		e->temp = e->temp->next;
	}*/
	return (0);
}
