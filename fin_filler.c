/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fin_filler.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 06:21:51 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 12:41:28 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	fin_filler(t_e *e)
{
	get_next_line(0, NULL);
	free_line(&e->line);
	ft_free_list_coor(&e->coor_piece);
	ft_free_list_coor(&e->coor_me);
	ft_free_list_coor(&e->coor_en);
	free_map(&e->map, e->size_map.y);
	free_map(&e->piece, e->size_piece.y);
	while (1)
	{
	}
	ft_printf("%d %d\n", 0, 0);
}
