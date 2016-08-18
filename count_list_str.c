/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_list_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 16:19:16 by ajubert           #+#    #+#             */
/*   Updated: 2016/07/25 16:34:48 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_list_str(t_list_str *list)
{
	t_list_str	*temp;
	int			i;

	i = 0;
	temp = list->next;
	while (temp != list)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}
