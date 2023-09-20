/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 16:39:17 by marvin            #+#    #+#             */
/*   Updated: 2023/05/02 16:39:17 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//ADD TO LIBFT!!!!!
t_stack	*ft_lstsectolast(t_stack *lst)
{
	t_stack *next;

	while (lst)
	{
		next = lst->next;
		if (!next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}


//call with stack_a for sa and stack_b for sb. For ss just call it twice with both
void	ft_sa(t_stack **head)
{
	t_stack *stack;
	t_stack *stack1;
	t_stack *stack2;

	stack = *head;
	stack1 = stack->next;
	stack2 = stack1->next;
	if (!*head || !stack1)
		return ;
	stack1->next = stack;
	stack->next = stack2;
	*head = stack1;
	ft_printf("%s\n", "sa");
}

void	ft_sb(t_stack **head)
{
	t_stack *stack;
	t_stack *stack1;
	t_stack *stack2;

	stack = *head;
	stack1 = stack->next;
	stack2 = stack1->next;
	if (!*head || !stack1)
		return ;
	stack1->next = stack;
	stack->next = stack2;
	*head = stack1;
	ft_printf("%s\n", "sb");
}

void	ft_ss(t_stack **stack_a, t_stack **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	ft_printf("%s\n", "ss");
}

void	ft_pa(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *afirst;
	t_stack *bfirst;

	if (!*stack_b)
		return ;
	afirst = *stack_a;
	bfirst = *stack_b;
	*stack_b = bfirst->next;
	bfirst->next = afirst;
	*stack_a = bfirst;
	ft_printf("%s\n", "pa");
}

void	ft_pb(t_stack **stack_a, t_stack **stack_b)
{
	t_stack *afirst;
	t_stack *bfirst;

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
	t_stack *lstlast;
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
	t_stack *lstlast;
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
	t_stack *lstlast;
	t_stack	*lstsectolast;
	t_stack *lstfirst;

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

void	ft_rrb(t_stack	**stack)
{
	t_stack *lstlast;
	t_stack	*lstsectolast;
	t_stack *lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
	ft_printf("%s\n", "rrb");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("%s\n", "rrr");
}



