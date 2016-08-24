/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_card.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 01:09:10 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 01:17:54 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_card(t_e *e)
{
	e->hg.h = ft_init_pos(-1, -1);
	e->hg.d = ft_init_pos(-1, -1);
	e->hg.b = ft_init_pos(-1, -1);
	e->hg.g = ft_init_pos(-1, -1);
	e->hd.h = ft_init_pos(-1, -1);
	e->hd.d = ft_init_pos(-1, -1);
	e->hd.b = ft_init_pos(-1, -1);
	e->hd.g = ft_init_pos(-1, -1);
	e->bg.h = ft_init_pos(-1, -1);
	e->bg.d = ft_init_pos(-1, -1);
	e->bg.b = ft_init_pos(-1, -1);
	e->bg.g = ft_init_pos(-1, -1);
	e->bd.h = ft_init_pos(-1, -1);
	e->bd.d = ft_init_pos(-1, -1);
	e->bd.b = ft_init_pos(-1, -1);
	e->bd.g = ft_init_pos(-1, -1);
}
