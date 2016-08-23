/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/25 14:52:24 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/23 11:58:07 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include "filler.h"

int		main(void)
{
	t_e		e;
	int		result;

	ft_bzero(&e, sizeof(t_e));
	e.fd = open("debug.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
	e.fd1 = open("output.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
	e.fd2 = open("circle.txt", O_CREAT | O_RDWR | O_APPEND, 0640);
//		ft_printf("%d %d", 8, 2);
//	if (!(first_map(&e)))
//		return (0);
//	ft_printf_fd(e.fd2, "valid_circle1 : %d       valid_circle2 : %d\n", e.valid_circle1, e.valid_circle2);
	search_char(&e);
	first_map(&e);
	if (e.error_map)
	{
		ft_printf("0 0\n");
		return (0);
	}
	get_piece(&e);
//	ft_printf_fd(e.fd, "avant recup_coord_piece\n");
	recup_coord_piece(&e);
	first_pos(&e);
//	ft_printf_fd(e.fd, "avant move_to_mid\n");
//	if (e.strat == 0)
		result = move_to_mid(&e);
	if (result == 0)
	{
		move_to_en(&e);
	}
	if (result == 2)
		e.strat = 1;
	if (e.strat == 1)
		move_to_en(&e);
	//ft_printf("%d %d\n", , );
//	ft_printf_fd(e.fd, "avant printf\n");
		ft_printf("%d %d\n", e.pos_piece.y, e.pos_piece.x);
//	ft_printf_fd(e.fd, "avant free_piece\n");
	free_piece(e.piece, e.size_piece.y);
//	ft_printf_fd(e.fd, "avant ft_free_list_coor\n");
//	ft_free_list_coor(e.coor_piece);
	e.coor_piece = NULL;
	while (get_map(&e))
	{
		test_valid_point_me(&e);
		get_piece(&e);
		recup_coord_piece(&e);
		if (e.strat == 0)
		{
			result = move_to_mid(&e);
			if (result == 0)
			{
				//if (move_to_en(&e) == 0)
					if (move_to_random(&e) == 0)
						return (0);
			}
		}
		if (result == 2)
		{
			result = -1;
			e.strat = 1;
		}
		if (e.strat == 1)
			if (circle_en(&e) == 0)
			{
		//		if (move_to_en(&e) == 0)
					if (move_to_random(&e) == 0)
						return (0);
			}
		if (e.strat == 2)
		{
		//	if (move_to_en(&e))
				if (move_to_random(&e) == 0)
					return (0);
		}
		if (e.strat == 3)
			if (move_to_random(&e) == 0)
				return (0);
		ft_printf("%d %d\n", e.pos_piece.y, e.pos_piece.x);
		free_piece(e.piece, e.size_piece.y);
//		ft_free_list_coor(e.coor_piece);
	e.coor_piece = NULL;
	}
	free_map(e.map, e.size_map.y);
//	ft_printf("plop");
//recup_size_tab(&e);
//	recup_tab(&e);
//	if (e.me == 'O')
//	else
//		ft_printf("%d %d", 12, 14);
/*	recup_size_tab(&e);
	recup_tab(&e);
	recup_size_piece(&e);
	recup_piece(&e);
	coordonne_piece(&e);
	calc_dist(&e);
	e.dist_secur = calc_dist_circle(&e);
	e.horizon_me = what_horizon(e.me_pos.y, e.center.y);
	e.horizon_en = what_horizon(e.ennemy_pos.y, e.center.y);
	e.verticale_me = what_horizon(e.me_pos.x, e.center.x);
	e.verticale_en = what_horizon(e.ennemy_pos.x, e.center.x);
	e.dist_center_en = calc_dist_to_center(&e, e.ennemy_pos);
	e.dist_center_me = calc_dist_to_center(&e, e.me_pos);
	e.strat = what_strat(&e);
	first_pos(e);*/
	return(0);
}
