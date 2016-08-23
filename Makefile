# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2016/08/23 07:57:58 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		ajubert.filler
COMPILER=	gcc
FLAG=		-Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/
vpath %.c

SRC_C=	main.c\
		list.c\
		count_list_str.c\
		first_map.c\
		search_char.c\
		recup_size_tab.c\
		recup_tab.c\
		free_line.c\
		free_map.c\
		get_piece.c\
		free_piece.c\
		recup_piece.c\
		recup_size_piece.c\
		get_map.c\
		first_pos.c\
		move_to_mid.c\
		recup_coord_piece.c\
		calc_dist_to_center.c\
		check_place.c\
		new_dist_to_center.c\
		print_coord.c\
		list_coor_piece.c\
		search_point_to_mid.c\
		ft_pos_in_map.c\
		mem_coord_me.c\
		print_coord_me.c\
		move_to_en.c\
		calc_dist_to_en.c\
		new_coord.c\
		new_dist_to_en.c\
		search_point_to_en.c\
		print_coord_en.c\
		circle_en.c\
		init_bloc_en.c\
		mem_bloc_en.c\
		move_to_circle.c\
		position_to_circle.c\
		calc_dist_to.c\
		new_dist_to.c\
		search_point_to.c\
		position_to_circle_bas.c\
		position_to_circle_droite.c\
		position_to_circle_gauche.c\
		position_to_circle_haut.c\
		position_to_circle_d_hd_bg.c\
		position_to_circle_d_hg_bd.c\
		verif_valid_circle.c\
		move_to_random.c\
		test_valid_point_me.c\
		free_maillon.c\
		ft_error_map.c

SRC_O=		$(SRC_C:.c=.o)

all: libft.h libft.a $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) -o $(NAME) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======FILLER HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $(subst __,/,$<) -o $@

libft.a:
	@echo "\033[32m==================================="
	@echo "==========COMPILING LIBFT=========="
	@echo "===================================\033[0m"
	make re -C ./libft/
	cp ./libft/libft.a .
	make fclean -C ./libft/

libft.h:
	cp ./libft/libft/libft.h .
	cp ./libft/libft/get_next_line.h .
	cp ./libft/printf/ft_printf.h .

clean:
	@echo "\033[33m==========REMOVING OBJ FILES==========\033[0m"
	rm -rf $(SRC_O)

fclean: clean
	@echo "\033[31m==========REMOVING BIN FILES==========\033[0m"
	rm -rf $(NAME) libft.a
	rm -rf libft.h
	rm -rf get_next_line.h
	rm -rf ft_printf.h

re: fclean all
