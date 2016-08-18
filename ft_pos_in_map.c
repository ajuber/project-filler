/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pos_in_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 04:19:38 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/15 04:24:33 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_pos		ft_pos_in_map(t_pos repere_map, t_pos repere, t_pos var)
{
	t_pos pos_in_map;
	t_pos diff;

	diff.x = var.x - repere.x;
	diff.y = var.y - repere.y;
	pos_in_map.x = repere_map.x + diff.x;
	pos_in_map.y = repere_map.y + diff.y;
	return (pos_in_map);
}
