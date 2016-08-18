/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_size_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 21:08:57 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/12 15:06:13 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	recup_size_piece(t_e *e, char *line)
{
	e->i = 0;
	while (!(ft_isdigit(line[e->i])))
		e->i++;
	e->size_piece.y = ft_atoi(&line[e->i]);
	while (ft_isdigit(line[e->i]))
		e->i++;
	while (!(ft_isdigit(line[e->i])))
		e->i++;
	e->size_piece.x = ft_atoi(&line[e->i]);
}
