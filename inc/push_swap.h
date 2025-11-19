/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teichelm <teichelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:54:18 by marvin            #+#    #+#             */
/*   Updated: 2025/11/19 14:31:26 by teichelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

t_stack	*ft_lstsectolast(t_stack *lst);
void	ft_sa(t_stack **head);
void	ft_sb(t_stack **head);
void	ft_ss(t_stack **stack_a, t_stack **stack_b);
void	ft_pa(t_stack **stack_a, t_stack **stack_b);
void	ft_pb(t_stack **stack_a, t_stack **stack_b);
void	ft_ra(t_stack	**stack);
void	ft_rb(t_stack	**stack);
void	ft_rr(t_stack **stack_a, t_stack **stack_b);
void	ft_rra(t_stack	**stack);
void	ft_rrb(t_stack	**stack);
void	ft_rrr(t_stack **stack_a, t_stack **stack_b);
void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_strrev(char **string);
t_stack	*ft_insert(int argc, char **argv);
t_stack	*ft_rev_bins(t_stack **list);
t_stack	*ft_initialize(t_stack *head, int argc);
char	*ft_binconvert(int num);
char	*ft_bincalculator(int num, int pot, int dec, char *bin);
int		*ft_sort(t_stack **p, int argc);
int		ft_bubblesort(int **arr, int argc, int swi);
void	ft_free(t_stack **head, int i);
int		ft_check_double(char **argv, char *str, int argc);
int		ft_checker(int argc, char **argv);
int		main(int argc, char **argv);
int		ft_digit_check(char *argv);
int		ft_strcmp(char *s1, char *s2);
void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int argc);
int		ft_split_stack(t_stack **stack_a, t_stack **stack_b, int argc);
void	ft_sort_min(t_stack **stack_a);
void	ft_sort_small(t_stack **stack_a, t_stack **stack_b, int argc);
int		main(int argc, char **argv);
int		ft_find_int(t_stack **stack_a, int find);
int		ft_binlen(int num);

// int     ft_strlen(const char *a);
// void	ft_lstadd_back(t_stack **lst, t_stack *new);
// t_stack *ft_lstlast(t_stack *lst);
// int     ft_atoi(const char *p);
// int     ft_isdigit(int a);
// int     ft_strlen(const char *a);
// int     ft_digit_check(char *argv);
#endif