/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:32:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 01:23:26 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*t_list_str		*ft_create_racine_str(void)
{
	t_list_str		*racine;

	if (!(racine = (t_list_str *)malloc(sizeof(t_list_str))))
		return (NULL);
	racine->previous = racine;
	racine->next = racine;
	return (racine);
}*/

t_coor_piece		*new_list_coor(char c, int y, int x)
{
	t_coor_piece *new;

	if (!(new = (t_coor_piece *)malloc(sizeof(t_coor_piece))))
		return (NULL);
	new->next = NULL;
	new->c = c;
	new->valid = 1;
	new->pos.x = x;
	new->pos.y = y;
	return (new);
}

t_coor_piece		*push_back_coor(t_coor_piece *begin_list, char c, int y, int x)
{
	t_coor_piece *new;
	t_coor_piece *tmp;

	new = new_list_coor(c, y, x);
	if (begin_list == NULL)
		begin_list = new;
	else
	{
		tmp = begin_list;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (begin_list);
}

void			ft_free_list_coor(t_coor_piece *begin_list)
{
	t_coor_piece *tmp;
	t_coor_piece *tmp1;

	tmp1 = begin_list->next;
	while (tmp1->next != NULL)
	{
		tmp = tmp1;
		tmp1 = tmp1->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&begin_list);
	tmp1 = NULL;
	begin_list = NULL;
}
