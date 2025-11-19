/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teichelm <teichelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:18:43 by marvin            #+#    #+#             */
/*   Updated: 2025/11/19 14:31:07 by teichelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void	ft_sort_big(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*ahead;
	t_stack	*bhead;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ahead = *stack_a;
	bhead = *stack_b;
	while (i < ft_binlen(argc - 1))
	{
		while (j < argc - 1)
		{
			if (i > ft_strlen(ahead->binary) - 1 || ahead->binary[i] == '0')
				ft_pb(&ahead, &bhead);
			else
				ft_ra(&ahead);
			j++;
		}
		i++;
		j = 0;
		while (bhead)
			ft_pa(&ahead, &bhead);
		*stack_a = ahead;
	}
}

int	ft_split_stack(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*ahead;
	t_stack	*bhead;
	int		pos;
	int		j;

	ahead = *stack_a;
	bhead = *stack_b;
	j = 0;
	while (argc - j >= argc / 2)
	{
		pos = ft_find_int(&ahead, j);
		while (*ahead->position != j)
		{
			if (pos > argc / 2)
				ft_rra(&ahead);
			else
				ft_ra(&ahead);
		}
		ft_pb(&ahead, &bhead);
		j++;
	}
	*stack_a = ahead;
	*stack_b = bhead;
	return (j);
}

void	ft_sort_min(t_stack **stack_a)
{
	t_stack	*ahead;

	ahead = *stack_a;
	if (*ahead->position != 2 && ft_find_int(&ahead, 2) == 1)
		ft_ra(&ahead);
	if (*ahead->position != 2 && ft_find_int(&ahead, 2) == 2)
		ft_rra(&ahead);
	if (ft_find_int(&ahead, 0) == 2)
	{
		ft_sa(&ahead);
		ft_rra(&ahead);
	}
	else
		ft_ra(&ahead);
	*stack_a = ahead;
}

void	ft_sort_small(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack	*ahead;
	t_stack	*bhead;
	int		j;

	ahead = *stack_a;
	bhead = *stack_b;
	if (argc <= 2)
		ft_sort_min(&ahead);
	else
	{
		j = ft_split_stack(&ahead, &bhead, argc);
		if (*ahead->position != j)
			ft_sa(&ahead);
		while (bhead)
			ft_pa(&ahead, &bhead);
	}
	*stack_a = ahead;
	*stack_b = bhead;
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (ft_checker(argc, argv) != 0)
		return (0);
	stack_a = ft_insert(argc, argv);
	if (!stack_a)
		return (0);
	stack_b = NULL;
	if (argc > 51)
		ft_sort_big(&stack_a, &stack_b, argc);
	else
		ft_sort_small(&stack_a, &stack_b, argc - 2);
	ft_free(&stack_a, 0);
	ft_free(&stack_b, 0);
}
