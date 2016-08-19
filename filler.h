/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajubert <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/21 13:51:02 by ajubert           #+#    #+#             */
/*   Updated: 2016/08/19 04:17:16 by ajubert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"

typedef struct		s_list_str
{
	char			*str;
	struct s_list_str	*next;
	struct s_list_str	*previous;
}					t_list_str;

typedef struct		s_pos
{
	int				x;
	int				y;
}					t_pos;

typedef struct		s_coor_piece
{
	t_pos			pos;
	char			c;
	struct s_coor_piece		*next;
}					t_coor_piece;

typedef struct		s_bloc_en
{
	t_pos			pos;
	int				nb;
}					t_bloc_en;

typedef struct		s_let
{
	char			low;
	char			up;
}					t_let;

typedef struct		s_e
{
	t_pos			pos_piece;
	t_pos			size_map;
	t_pos			size_piece;
	char			*line;
	t_list_str		*list;
	t_list_str		*temp;
	char			**map;
	char			**piece;
	int				size;
	int				p;
	int				i;
	int				dist_me_en;
	t_pos			me_pos;
	t_pos			en_pos;
	t_pos			center;
	int				dist_center_en;
	int				dist_center_me;
	int				horizon_me;
	int				horizon_en;
	int				verticale_me;
	int				verticale_en;
	int				strat;
	int				dist_secur;
	t_coor_piece	*coor_me;
	t_coor_piece	*coor_en;
	t_coor_piece	*coor_piece;
	t_coor_piece	*ind;
	t_coor_piece	*repere;
	char			me;
	char			en;
	int				nb_me;
	int				nb_point;
	int				fd;
	int				fd1;
	t_bloc_en		en_hg;
	t_bloc_en		en_hd;
	t_bloc_en		en_bg;
	t_bloc_en		en_bd;
	t_pos			en_haut;
	t_pos			en_bas;
	t_pos			en_gauche;
	t_pos			en_droit;
	int				my_bloc;
	int				en_bloc;
	t_pos			pos_circle1;
	t_pos			pos_circle2;
	int				valid_circle1;
	int				valid_circle2;
	int				what_pos;
	int				inc1;
	int				inc2;
}					t_e;

t_list_str			*ft_create_racine_str(void);
t_list_str			*push_back_str(t_list_str *list, char *str);
t_coor_piece		*push_back_coor(t_coor_piece *list, char c, int y, int x);
int					count_list_str(t_list_str *list);
int					get_map(t_e *e);
int					get_piece(t_e *e);
void				recup_size_tab(t_e *e, char *line);
void				recup_tab(t_e *e, int j, char *line);
void				recup_piece(t_e *e, int j, char *line);
void				recup_size_piece(t_e *e, char *line);
void				calc_dist(t_e *e);
int					calc_dist_to_center(t_e *e, t_pos var);
int					what_horizon(int var, int center);
int					what_strat(t_e *e);
int					calc_dist_circle(t_e *e);
void				search_char(t_e *e);
void				free_line(char *line);
void				free_map(char **map, int size);
void				free_piece(char **piece, int size);
int					move_to_mid(t_e *e);
int					first_map(t_e *e);
void				first_pos(t_e *e);
void				recup_coord_piece(t_e *e);
int					search_point_to_mid(t_e *e, int dist);
int					check_place(t_e *e, int j);
t_pos				ft_pos_in_map(t_pos repere_map, t_pos repere, t_pos var);
int					new_dist_to_center(t_e *e);
void				print_coord(t_e *e);
void				ft_free_list_coor(t_coor_piece *begin_list);
void				mem_coord_me(t_e *e);
void				print_coord_me(t_e *e);
int					move_to_en(t_e *e);
void				new_coord(t_e *e, char *map, char *line, int y);
int					calc_dist_to_en(t_e *e, t_pos var);
int					search_point_to_en(t_e *e, int dist);
int					new_dist_to_en(t_e *e);
void				print_coord_en(t_e *e);
void				init_bloc_en(t_e *e, int y, int x);
void				mem_bloc_en(t_e *e, int y, int x);
int					circle_en(t_e *e);
void				position_to_circle(t_e *e);
int					move_to_circle(t_e *e, t_pos cir);
int					search_point_to(t_e *e, int dist, t_pos cir);
int					calc_dist_to(t_pos var, t_pos var1);
int					new_dist_to(t_e *e, t_pos cir);

#endif
