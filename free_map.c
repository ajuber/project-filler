/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/12 14:42:34 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/25 12:08:15 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_map(char ***map, int y)
{
	int i;

	i = 0;
	while (map[0] && map[0][i] && i < y)
	{
		free(map[0][i]);
		map[0][i] = NULL;
		i++;
	}
	if (map[0])
		free(map[0]);
	map[0] = NULL;
}
