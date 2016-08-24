/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_piece.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 18:10:54 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:26:49 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		recup_piece(t_e *e, int j, char *line)
{
	if (e->piece == NULL)
		if (!(e->piece = (char **)malloc(sizeof(char *) * e->size_piece.y)))
			return (0);
	if (!(e->piece[j] = ft_strdup(line)))
		return (0);
	return (1);
}
