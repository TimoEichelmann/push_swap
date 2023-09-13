/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:54:18 by marvin            #+#    #+#             */
/*   Updated: 2023/03/25 18:54:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// # include "libft/libft.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

int ft_checker(int argc, char** argv);
int	ft_digit_check(char *argv);
int	ft_strcmp(char *s1, char *s2);
int	ft_strlen(const char *a);
int	ft_check_double(char **argv, char *str, int	argc);
int	ft_isdigit(int a);
int	ft_atoi(const char *p);

#endif