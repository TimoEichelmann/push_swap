/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 18:54:18 by marvin            #+#    #+#             */
/*   Updated: 2023/03/25 18:54:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"

typedef struct stack_a
{
	struct stack_a* prior;
	int value;
	int index_current;
	int index_goal;
	struct stack_a* next;
}stack_a;

typedef struct stack_b
{
	struct stack_b* prior;
	int value;
	int index_current;
	int index_goal;
	struct stack_b* next;
}stack_b;


#endif