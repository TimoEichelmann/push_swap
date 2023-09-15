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
stack_t	*ft_lstsectolast(stack_t *lst)
{
	stack_t *next;

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
void	ft_sa(stack_t **head)
{
	stack_t *stack;
	stack_t *stack1;
	stack_t *stack2;

	stack = *head;
	stack1 = stack->next;
	stack2 = stack1->next;
	if (!*head || !stack1)
		return ;
	stack1->next = stack;
	stack->next = stack2;
	*head = stack1;
	printf("%s\n", "sa");
}

void	ft_sb(stack_t **head)
{
	stack_t *stack;
	stack_t *stack1;
	stack_t *stack2;

	stack = *head;
	stack1 = stack->next;
	stack2 = stack1->next;
	if (!*head || !stack1)
		return ;
	stack1->next = stack;
	stack->next = stack2;
	*head = stack1;
	printf("%s\n", "sb");
}

void	ft_ss(stack_t **stack_a, stack_t **stack_b)
{
	ft_sa(stack_a);
	ft_sb(stack_b);
	printf("%s\n", "ss");
}

void	ft_pa(stack_t **stack_a, stack_t **stack_b)
{
	stack_t *afirst;
	stack_t *bfirst;

	if (!*stack_b)
		return ;
	afirst = *stack_a;
	bfirst = *stack_b;
	*stack_b = bfirst->next;
	bfirst->next = afirst;
	*stack_a = bfirst;
	printf("%s\n", "pa");
}

void	ft_pb(stack_t **stack_a, stack_t **stack_b)
{
	stack_t *afirst;
	stack_t *bfirst;

	if (!*stack_a)
		return ;
	afirst = *stack_a;
	bfirst = *stack_b;
	*stack_a = afirst->next;
	afirst->next = bfirst;
	*stack_b = afirst;
	printf("%s\n", "pb");
}

void	ft_ra(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstfirst;

	lstlast = ft_lstlast(*stack);
	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	*stack = lstfirst->next;
	lstfirst->next = lstlast->next;
	lstlast->next = lstfirst;
	printf("%s\n", "ra");
}

void	ft_rb(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstfirst;

	lstlast = ft_lstlast(*stack);
	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	*stack = lstfirst->next;
	lstfirst->next = lstlast->next;
	lstlast->next = lstfirst;
	printf("%s\n", "rb");
}

void	ft_rr(stack_t **stack_a, stack_t **stack_b)
{
	ft_ra(stack_a);
	ft_rb(stack_b);
	printf("%s\n", "rr");
}

void	ft_rra(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstsectolast;
	stack_t *lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
	printf("%s\n", "rra");
}

void	ft_rrb(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstsectolast;
	stack_t *lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
	printf("%s\n", "rrb");
}

void	ft_rrr(stack_t **stack_a, stack_t **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	printf("%s\n", "rrr");
}



