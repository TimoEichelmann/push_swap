/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/20 13:15:08 by marvin            #+#    #+#             */
/*   Updated: 2023/09/20 13:15:08 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_bubblesort(int **arr, int argc, int swi)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < argc - 1)
	{
		while (j < (argc - i - 1))
		{
			if (*(*arr + j) > *(*arr + (j + 1)))
			{
				tmp = *(*arr + j);
				*(*arr + j) = *(*arr + (j + 1));
				*(*arr + (j + 1)) = tmp;
				swi++;
			}
			j++;
		}
		i++;
		j = 0;
	}
	return (swi);
}

int	*ft_sort(t_stack **arr, int argc)
{
	int		*result;
	int		i;
	int		swi;
	t_stack	*p;

	p = *arr;
	i = 0;
	swi = 0;
	result = malloc(sizeof(int) * (argc - 1));
	while (p)
	{
		result[i] = *p->value;
		p = p->next;
		i++;
	}
	swi = ft_bubblesort(&result, argc, swi);
	if (swi == 0)
	{
		free (result);
		return (NULL);
	}
	return (result);
}

char	*ft_bincalculator(int num, int pot, int dec, char *bin)
{
	int	i;
	int	rem;

	i = 0;
	bin = malloc((sizeof(char) * dec) + 1);
	while (pot != 0)
	{
		rem = num % pot;
		num = num / pot;
		pot = pot / 2;
		bin[i] = '0' + num;
		dec--;
		num = rem;
		i++;
	}
	bin[i] = '\0';
	return (bin);
}

char	*ft_binconvert(int num)
{
	int		pot;
	int		dec;
	char	*bin;

	pot = 1;
	dec = 1;
	bin = NULL;
	while (num / pot > 1)
	{
		pot = pot * 2;
		dec++;
	}
	return (ft_bincalculator(num, pot, dec, bin));
}

t_stack	*ft_initialize(t_stack *head, int argc)
{
	t_stack	*p;
	int		*sorted;
	int		i;

	i = 0;
	sorted = ft_sort(&head, argc - 1);
	if (!sorted)
		return (NULL);
	p = head;
	while (p)
	{
		while (*p->value != sorted[i])
			i++;
		p->position = malloc(sizeof(int));
		*p->position = i;
		p->binary = ft_binconvert(*p->position);
		if (!p->position || !p->binary)
			return (NULL);
		i = 0;
		p = p->next;
	}
	free(sorted);
	return (head);
}
