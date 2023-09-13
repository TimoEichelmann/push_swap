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

int main(int argc, char **argv)
{
	stack_t *stack_a;
	stack_t *stack_b;

	if (ft_checker(argc, argv) != 0)
		return (0);
	stack_a = ft_initiate(argv);
	if (!stack_a)
		return (0);
	stack_b = malloc(sizeof(stack_t));
	
}