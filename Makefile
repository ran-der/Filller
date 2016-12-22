# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rvan-der <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/11 14:44:06 by rvan-der          #+#    #+#              #
#    Updated: 2016/12/11 16:46:28 by rvan-der         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rvan-der.filler
CC = gcc
CFLAG = -Wall -Werror -Wextra
SRC = main_filler.c \
	  read.c \
	  get_skin.c
	  get_plt.c \
	  distance.c \
	  crdlist.c 

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(SRC)
	make -C libft
	$(CC) $(CFLAG) -c -Llibft -lft $(SRC)
	$(CC) $(OBJ)

clean:
	make -C libft clean
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f libft/libft.a

re: fclean all
