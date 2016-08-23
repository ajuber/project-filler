/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_valid_point_me.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 01:30:12 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 07:13:29 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static int		check_valid(t_e *e, t_pos pos, t_coor_piece *p)
{
	if (pos.y - 1 >= 0 && pos.x - 1 >= 0 && e->map[pos.y - 1][pos.x - 1] == '.')
		return (1);
	if (pos.y - 1 >= 0 && e->map[pos.y - 1][pos.x] == '.')
		return (1);
	if (pos.y - 1 >= 0 && pos.x + 1 < e->size_map.x && e->map[pos.y - 1][pos.x + 1] == '.')
		return (1);
	if (pos.x + 1 < e->size_map.x && e->map[pos.y][pos.x + 1] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && pos.x + 1 < e->size_map.x && e->map[pos.y + 1][pos.x + 1] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && e->map[pos.y + 1][pos.x] == '.')
		return (1);
	if (pos.y + 1 < e->size_map.y && pos.x - 1 > 0 && e->map[pos.y + 1][pos.x - 1] == '.')
		return (1);
	if (pos.x - 1 > 0 && e->map[pos.y][pos.x - 1] == '.')
		return (1);
	p->valid = 0;
	e->nb_me--;
	return (0);
}

void			test_valid_point_me(t_e *e)
{
	t_coor_piece *tmp;
	t_coor_piece *tmp_previous;
	t_coor_piece *tmp_next;
	int			test;

	test = 0;
	tmp = NULL;
	tmp_next = NULL;
	tmp_previous = e->coor_me;
	tmp = e->coor_me;
	while (tmp)
	{
		if (tmp->valid)
		{
			check_valid(e, tmp->pos, tmp);
		}
		tmp = tmp->next;
	}
/*	if (tmp_previous->next)
		tmp = tmp_previous->next;
	if (tmp->next)
		tmp_next = tmp->next;
	while (tmp && tmp->next)
	{
			test += 1;
		ft_printf_fd(e->fd, "%d\n", test);
		if (tmp->valid)
		{
			if (check_valid(e, tmp->pos, tmp) == 0)
			{
				free_maillon(tmp);
				tmp_previous->next = tmp_next;
				tmp = tmp_previous;
				tmp_next = tmp_next->next;
			}
		}
		tmp_previous = tmp;
		tmp = tmp->next;
		if (tmp_next)
			tmp_next = tmp_next->next;
	}*/
}
