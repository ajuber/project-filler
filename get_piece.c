/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 15:00:07 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/12 15:30:00 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "filler.h"

int		get_piece(t_e *e)
{
	int j;
	int fd;

	fd = open("output.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
//	(void)e;
//	write(1, "8 2", 3);
	e->line = NULL;
	e->piece = NULL;
	while (get_next_line(0, &e->line) > 0)
	{
		if (ft_strstr(e->line, "Piece"))
		{
			recup_size_piece(e, e->line);
			j = 0;
			while (get_next_line(0, &e->line) > 0)
			{
				recup_piece(e, j, e->line);
				ft_printf_fd(fd, "%s\n", e->line);
				j++;
				if (j == e->size_piece.y)
				{
					free_line(e->line);
					return (1);
				}
				free_line(e->line);
			}
		}
		free_line(e->line);
	}
	free_line(e->line);
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
