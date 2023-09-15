/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:18:43 by marvin            #+#    #+#             */
/*   Updated: 2023/05/09 00:18:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_big(stack_t **stack_a, stack_t **stack_b, int argc)
{
	stack_t *ahead;
	stack_t *bhead;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ahead = *stack_a;
	bhead = *stack_b;
	while (i <= ft_strlen(ft_binconvert(argc)))
	{
		while (j < argc)
		{
			if (ahead->value[i] == '0')
				ft_pb(&ahead, &bhead);
			else
				ft_ra(&ahead);
			j++;
		}
		i++;
		while (bhead)
			ft_pa(&ahead, &bhead);
	}
	bhead = ahead;
	while (ahead)
	{
		printf("%d\n", *ahead->value);
		ahead = ahead->next;
	}
}

int main(int argc, char **argv)
{
	stack_t *stack_a;
	stack_t *stack_b;

	if (ft_checker(argc, argv) != 0)
		return (0);
	stack_a = ft_insert(argc, argv);
	// stack_b = stack_a;
	// while (stack_a)
	// {
	// 	printf("%d\n", *stack_a->value);
	// 	stack_a = stack_a->next;
	// }
	// stack_a = stack_b;
	if (!stack_a)
		return (0);
	stack_b = NULL;
	if (argc > 11)
		ft_sort_big(&stack_a, &stack_b, argc);
	ft_free(&stack_a);
}