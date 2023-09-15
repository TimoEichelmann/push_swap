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

stack_t	*ft_lstsectolast(stack_t *lst);
void    ft_sa(stack_t **head);
void    ft_sb(stack_t **head);
void    ft_ss(stack_t **stack_a, stack_t **stack_b);
void    ft_pa(stack_t **stack_a, stack_t **stack_b);
void    ft_pb(stack_t **stack_a, stack_t **stack_b);
void    ft_ra(stack_t	**stack);
void    ft_rb(stack_t	**stack);
void    ft_rr(stack_t **stack_a, stack_t **stack_b);
void    ft_rra(stack_t	**stack);
void    ft_rrb(stack_t	**stack);
void    ft_rrr(stack_t **stack_a, stack_t **stack_b);
void    ft_sort_big(stack_t **stack_a, stack_t **stack_b, int argc);
void    ft_strrev(char **string);
stack_t *ft_insert(int argc, char **argv);
stack_t *ft_rev_bins(stack_t **list);
stack_t *ft_initialize(stack_t *head, int argc);
char	*ft_binconvert(int	num);
char    *ft_bincalculator(int num, int pot, int dec, char *bin);
int     *ft_sort(stack_t *p, int argc);
int     ft_bubblesort(int **arr, int argc, int swi);
void    ft_free(stack_t **head);
int     ft_check_double(char **argv, char *str, int	argc);
int     ft_checker(int argc, char** argv);
int     main(int argc, char **argv);

int     ft_strlen(const char *a);
void	ft_lstadd_back(stack_t **lst, stack_t *new);
stack_t *ft_lstlast(stack_t *lst);
int     ft_atoi(const char *p);
int     ft_isdigit(int a);
int     ft_strlen(const char *a);
int     ft_strcmp(char *s1, char *s2);
int     ft_digit_check(char *argv);
#endif