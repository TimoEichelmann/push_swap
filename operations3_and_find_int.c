/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:18:27 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 13:18:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrb(t_stack	**stack)
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
	ft_printf("%s\n", "rrb");
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_rra(stack_a);
	ft_rrb(stack_b);
	ft_printf("%s\n", "rrr");
}

int	ft_find_int(t_stack **stack_a, int find)
{
	int		i;
	t_stack	*ahead;

	ahead = *stack_a;
	i = 0;
	while (*ahead->position != find && ahead)
	{
		ahead = ahead->next;
		i++;
	}
	if (!ahead && *ahead->position != i)
		return (-1);
	return (i);
}

int		ft_binlen(int num)
{
	int		pot;
	int		dec;

	pot = 1;
	dec = 1;
	while (num / pot > 1)
	{
		pot = pot * 2;
		dec++;
	}
	return (dec);
}
