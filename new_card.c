/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_card.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 01:45:44 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 01:53:32 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_card		new_card(t_card card, int y, int x)
{
	if (card.h.y == -1)
		card = init_pos_card(y, x);
	else
	{
		if (y < card.h.y)
			card.h = ft_init_pos(y, x);
		if (y > card.b.y)
			card.b = ft_init_pos(y, x);
		if (x < card.g.x)
			card.g = ft_init_pos(y, x);
		if (x > card.d.x)
			card.d = ft_init_pos(y, x);
	}
	return (card);
}
