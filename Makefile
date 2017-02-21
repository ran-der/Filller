# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:44:06 by rvan-der          #+#    #+#              #
#    Updated: 2017/02/21 12:10:55 by rvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rvan-der.filler
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main_filler.c get_plateau.c read.c get_ennemi.c get_skin.c skin_tests.c \
	  skin_list.c get_square.c is_insight.c delete_ft.c coord_list.c\
	  find_dir.c is_surface.c fill_area.c surround.c counter.c player.c \
	  distance.c

OBJ = $(SRC:.c=.o)

.SUFFIXES:

all: $(NAME)

libraries:
	make -C libft
	mv libft/libft.a ./libft.a

$(NAME): $(SRC) libraries
	#$(CC) $(CFLAG) -c $(SRC)
	$(CC) $(SRC) -L. -lft -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	#rm -f libft/libft.a

re: fclean all
