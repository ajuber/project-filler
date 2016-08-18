/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:42:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/12 15:31:04 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_piece(char **piece, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		free(piece[i]);
		piece[i] = NULL;
		i++;
	}
	free(piece);
	piece = NULL;
}
