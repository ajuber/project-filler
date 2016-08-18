/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:10:54 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/12 15:09:30 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	recup_piece(t_e *e, int j, char *line)
{
	if (e->piece == NULL)
		e->piece = (char **)malloc(sizeof(char *) * e->size_piece.y);
	e->piece[j] = ft_strdup(line);
}
