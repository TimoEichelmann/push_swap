/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teichelm <teichelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:17:55 by marvin            #+#    #+#             */
/*   Updated: 2025/11/19 14:30:51 by teichelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*afirst;
	t_stack	*bfirst;

	if (!*stack_a)
		return ;
	afirst = *stack_a;
	bfirst = *stack_b;
	*stack_a = afirst->next;
	afirst->next = bfirst;
	*stack_b = afirst;
	ft_printf("%s\n", "pb");
}

void	ft_ra(t_stack	**stack)
{
	t_stack	*lstlast;
	t_stack	*lstfirst;

	lstlast = ft_lstlast(*stack);
	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	*stack = lstfirst->next;
	lstfirst->next = lstlast->next;
	lstlast->next = lstfirst;
	ft_printf("%s\n", "ra");
}

void	ft_rb(t_stack	**stack)
{
	t_stack	*lstlast;
	t_stack	*lstfirst;

	lstlast = ft_lstlast(*stack);
	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	*stack = lstfirst->next;
	lstfirst->next = lstlast->next;
	lstlast->next = lstfirst;
	ft_printf("%s\n", "rb");
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	ft_printf("%s\n", "rr");
}

void	ft_rra(t_stack	**stack)
{
	t_stack	*lstlast;
	t_stack	*lstsectolast;
	t_stack	*lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
	ft_printf("%s\n", "rra");
}
