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

void	ft_sa(stack_t *stack_a)
{
	stack_t *next_a;

	next_a = stack_a->next;
	if ((!stack_a)	||	(!next_a))
		return ;
	stack_a->next = next_a->next;
	next_a->next = stack_a;
}

void	ft_sb(stack_t *stack_a, stack_t *stack_b)
{
	stack_t *next_a;
	stack_t *next_b;

	if ((!stack_b && !stack_a)	||
			(!stack_a || !stack_b))
		return ;
	next_a = stack_a->next;
	next_b = stack_b->next;
	stack_b->next = next_a;
	stack_a->next = next_b;
}