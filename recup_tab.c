/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:41:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/24 08:38:48 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		recup_tab(t_e *e, int j, char *line)
{
	if (e->map == NULL)
		if (!(e->map = (char **)malloc(sizeof(char *) * e->size_map.y)))
			return (0);
	if (!(e->map[j] = ft_strdup(&line[4])))
		return (0);
	return (1);
}
