# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ajubert <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/05 14:28:27 by ajubert           #+#    #+#              #
#    Updated: 2016/08/17 23:37:16 by ajubert          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		ajubert.filler
COMPILER=	gcc
FLAG=		-Wall -Werror -Wextra
LIB=		libft.a
INCLUDES=	-I ./libft/includes/

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
		print_coord_en.c

SRC_O=		$(SRC_C:.c=.o)

all: libft.h libft.a $(NAME)

$(NAME): $(SRC_O)
	$(COMPILER) -o $(NAME) $(SRC_O) $(LIB) $(FLAG)
	@echo "\033[32m=======FILLER HAS BEEN CREATED=======\033[0m"

%.o: %.c
	$(COMPILER) $(FLAG) -c $<

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
