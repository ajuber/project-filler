/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:41:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/12 14:17:21 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	recup_tab(t_e *e, int j, char *line)
{
	if (e->map == NULL)
		e->map = (char **)malloc(sizeof(char *) * e->size_map.y);
	e->map[j] = ft_strdup(&line[4]);
}
