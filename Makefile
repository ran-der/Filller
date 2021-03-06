# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:44:06 by rvan-der          #+#    #+#              #
#    Updated: 2017/02/27 18:00:34 by rvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rvan-der.filler
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main_filler.c get_plateau.c read.c get_ennemi.c get_skin.c skin_tests.c \
	  skin_list.c get_square.c is_insight.c delete_ft.c coord_list.c\
	  find_dir.c is_surface.c fill_area.c surround.c counter.c play.c \
	  distance.c

OBJ = $(SRC:.c=.o)

.SUFFIXES:

all: $(NAME)


$(NAME): $(SRC)
	make -C libft
	$(CC) $(CFLAG) -c $(SRC)
	$(CC) $(OBJ) -Llibft -lft -o $(NAME)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
