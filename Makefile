# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: marvin <marvin@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:51:20 by marvin            #+#    #+#              #
#    Updated: 2023/09/19 15:51:20 by marvin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC = check.c insert.c operations.c push_swap.c
OBJ = check.o insert.o operations.o push_swap.o
LIBFT_OBJS = libft.a

all : $(NAME)
$(NAME) : $(OBJ) $(LIBFT_OBJS)
	cc -Wall -Werror -Wextra -Lft -o push_swap $(OBJ) $(LIBFT_OBJS)
$(OBJ) : $(SRC)
	cc -c -Wall -Werror -Wextra $(SRC)
$(LIBFT_OBJS):
	cd ./libft && make
	cd ./libft && mv libft.a "../"
	cd ./libft && make fclean
clean:
	-rm -f $(OBJ) $(LIBFT_OBJS)
	cd libft && make clean
fclean: clean
	-rm -f $(NAME)
	cd libft && make clean
re: fclean all