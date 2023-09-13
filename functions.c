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

#include <stdio.h>
#include <unistd.h>
#include "push_swap.h"

//call with stack_a for sa and stack_b for sb. For ss just call it twice with both
void	ft_swap(stack_t **head)
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
}