/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_size_piece.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 21:08:57 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:44:40 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		recup_size_piece(t_e *e, char *line)
{
	e->i = 0;
	while (line[e->i] && !(ft_isdigit(line[e->i])))
		e->i++;
	if (line[e->i] == '\0')
		return (0);
	e->size_piece.y = ft_atoi(&line[e->i]);
	while (line[e->i] && ft_isdigit(line[e->i]))
		e->i++;
	while (line[e->i] && !(ft_isdigit(line[e->i])))
		e->i++;
	if (line[e->i] == '\0')
		return (0);
	e->size_piece.x = ft_atoi(&line[e->i]);
	return (1);
}
