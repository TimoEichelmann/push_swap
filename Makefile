# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: teichelm <teichelm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/19 15:51:20 by marvin            #+#    #+#              #
#    Updated: 2025/11/19 14:34:07 by teichelm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
SRC_DIR= src
FULL_SRC= $(addprefix $(SRC_DIR)/, $(SRC) )
SRC = check.c insert.c initialize.c operations1.c operations2.c operations3_and_find_int.c push_swap.c
OBJ = check.o insert.o initialize.o operations1.o operations2.o operations3_and_find_int.o push_swap.o
LIBFT_OBJS = libft.a

all : $(NAME)
$(NAME) : $(OBJ) $(LIBFT_OBJS)
	cc -Wall -Werror -Wextra -Lft -o push_swap $(OBJ) $(LIBFT_OBJS)
$(OBJ) : $(FULL_SRC)
	cc -c -Wall -Werror -Wextra $(FULL_SRC)
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