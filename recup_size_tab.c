/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recup_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 16:41:09 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/17 02:08:31 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	recup_size_tab(t_e *e, char *line)
{
	e->i = 0;
	while (!(ft_isdigit(line[e->i])))
		e->i++;
	e->size_map.y = ft_atoi(&line[e->i]);
	while (ft_isdigit(line[e->i]))
		e->i++;
	while (!(ft_isdigit(line[e->i])))
		e->i++;
	e->size_map.x = ft_atoi(&line[e->i]);
	e->center.x = e->size_map.x / 2;
	e->center.y = e->size_map.y / 2;
	e->dist_secur = (e->size_map.x + e->size_map.y) / 10;
	ft_printf_fd(e->fd1, "center.x : %d      center.y : %d", e->center.x, e->center.y);
}
