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
LIBFT_OBJS = ft_hexnmbs.o ft_ints.o ft_main.o ft_atoi.o ft_bzero.o ft_calloc.o ft_isalnum.o ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o ft_memchr.o ft_memcmp.o ft_memcpy.o ft_memmove.o ft_memset.o ft_putchar_fd.o ft_putendl_fd.o ft_putnbr_fd.o ft_putstr_fd.o ft_split.o ft_strchr.o ft_strdup.o ft_striteri.o ft_strjoin.o ft_strlcat.o ft_strlcpy.o ft_strlen.o ft_strmapi.o ft_strncmp.o ft_strnstr.o ft_strrchr.o ft_strtrim.o ft_substr.o ft_tolower.o ft_toupper.o

all : $(NAME)
$(NAME) : $(OBJ) $(LIBFT_OBJS)
	cc -Wall -Werror -Wextra -o $(OBJ) $(LIBFT_OBJS) $(NAME)
$(OBJ) : $(SRC)
	cc -c -Wall -Werror -Wextra $(SRC)
$(LIBFT_OBJS):
	cd ./libft && make
	cd ./libft && mv *.o "../"
	cd ./libft && make fclean
clean:
	-rm -f $(OBJ) $(LIBFT_OBJS)
	cd libft && make clean
fclean: clean
	-rm -f $(NAME)
	cd libft && make clean
re: fclean all