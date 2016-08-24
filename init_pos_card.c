/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos_card.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 01:22:02 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 01:26:37 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_card		init_pos_card(int y, int x)
{
	t_card card;

	card.h = ft_init_pos(y, x);
	card.d = ft_init_pos(y, x);
	card.b = ft_init_pos(y, x);
	card.g = ft_init_pos(y, x);
	return (card);
}
