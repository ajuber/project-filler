/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/11 15:32:08 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/11 15:32:10 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_list_str		*ft_create_racine_str(void)
{
	t_list_str		*racine;

	if (!(racine = (t_list_str *)malloc(sizeof(t_list_str))))
		return (NULL);
	racine->previous = racine;
	racine->next = racine;
	return (racine);
}

t_list_str		*new_list_str(t_list_str *racine, char *str)
{
	t_list_str *new;

	if (!(new = (t_list_str *)malloc(sizeof(t_list_str))))
		return (NULL);
	new->next = racine;
	new->previous = racine;
	new->str = ft_strdup(str);
	return (new);
}

t_list_str		*push_back_str(t_list_str *begin_list, char *str)
{
	t_list_str *new;
	t_list_str *tmp;

	new = new_list_str(begin_list, str);
	if (begin_list->previous == begin_list && begin_list->next == begin_list)
		begin_list->next = new;
	else
	{
		tmp = begin_list->previous;
		tmp->next = new;
		new->previous = tmp;
	}
	begin_list->previous = new;
	return (begin_list);
}

t_list_str		*ft_free_maillon_str(t_list_str *maillon1, t_list_str *maillon2)
{
	t_list_str *tmp;
	t_list_str *tmp1;

	tmp = maillon1->previous;
	tmp1 = maillon2->next;
	ft_memdel((void **)&maillon1->str);
	ft_memdel((void **)&maillon1);
	ft_memdel((void **)&maillon2->str);
	ft_memdel((void **)&maillon2);
	tmp->next = tmp1;
	tmp1->previous = tmp;
	return (tmp1);
}

void			ft_free_list_str(t_list_str *begin_list)
{
	t_list_str *tmp;
	t_list_str *tmp1;

	tmp1 = begin_list->next;
	while (tmp1 != begin_list)
	{
		tmp = tmp1;
		tmp1 = tmp1->next;
		ft_memdel((void **)&tmp);
	}
	ft_memdel((void **)&begin_list);
	tmp1 = NULL;
}
