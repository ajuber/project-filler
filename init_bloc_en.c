/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bloc_en.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/18 03:57:59 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/18 05:13:46 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_bloc_en(t_e *e, int y, int x)
{
	e->en_hg.pos.y = y;
	e->en_hg.pos.x = x;
	e->en_hd.pos.y = y;
	e->en_hd.pos.x = x;
	e->en_bg.pos.y = y;
	e->en_bg.pos.x = x;
	e->en_bd.pos.y = y;
	e->en_bd.pos.x = x;
	e->en_hg.nb = 0;
	e->en_hd.nb = 0;
	e->en_bg.nb = 0;
	e->en_bd.nb = 0;
}
