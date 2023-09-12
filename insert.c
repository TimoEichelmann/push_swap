/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:18:15 by marvin            #+#    #+#             */
/*   Updated: 2023/05/09 00:18:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
// #include "push_swap.h"

void ft_free(stack_t *head)
{
	stack_t	*p;
	while (head)
	{
		p = head->next;
		free(head->value);
		free(head->position);
		free(head->binary);
		free(head);
		head = p;
	}
	return;
}

int	ft_atoi(const char *p)
{
	int	i;
	int	result;
	int	sign;

	sign = 1;
	result = 0;
	i = 0;
	while (p[i] == ' ' || p[i] == '\f' || p[i] == '\n' || p[i] == '\r'
		|| p[i] == '\t' || p[i] == '\v')
		i++;
	if (p[i + 1] >= '0' && p[i + 1] <= '9' && (p[i] == '-' || p[i] == '+'))
	{
		if (p[i] == '-')
			sign = -1;
		i++;
	}
	else if ((p[i] == '-' || p[i] == '+') && !(p[i + 1] >= '0' && p[i] <= '9'))
		return (0);
	while (p[i] >= '0' && p[i] <= '9')
	{
		result = result * 10 + (p[i] - '0');
		i++;
	}
	return (result * sign);
}

stack_t	*ft_lstlast(stack_t *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(stack_t **lst, stack_t *new)
{
	stack_t	*last;

	if (*lst && lst)
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	else
		*lst = new;
}

int    ft_bubblesort(int **arr, int argc, int swi)
{
    int    i;
    int    j;
    int    tmp;

    i = 0;
    j = 0;
    while (i < argc)
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

int	*ft_sort(stack_t *p, int argc)
{
	int	*result;
	int	i;
	int swi;

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
		return NULL;
	}
	return (result);
}

char *ft_bincalculator(int num, int pot, int dec, char *bin)
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
char	*ft_binconvert(int	num)
{
	int pot;
	int dec;
	char *bin;

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

void ft_initialize(stack_t *head, int argc)
{
	stack_t	*p;
	int		*sorted;
	int		i;

	i = 0;
	sorted = ft_sort(head, argc);
	if (!sorted)
	{
		ft_free(head);
		return ;
	}
	p = head;
	while (p)
	{
		while (*p->value != sorted[i])
			i++;
		p->position = malloc(sizeof(int));
		*p->position = i;
		p->binary = ft_binconvert(*p->position);
		i = 0;
		p = p->next;
	}
	free(sorted);
	return ;
}

stack_t	*ft_insert(int argc, char **argv)
{
    int    i;
    stack_t *head;
    stack_t *p;

    i = 1;
    head = NULL;
    while (i < argc)
    {
        p = malloc(sizeof(stack_t));
		p->value = malloc(sizeof(int));
        *p->value = ft_atoi(argv[i]);
        p->next = NULL;
        ft_lstadd_back(&head, p);
        i++;
    }
	ft_initialize(head, argc);
	if (!head)
		return NULL;
    return (head);
}

int main(int argc, char **argv)
{
	stack_t* head;
	stack_t *p;

	head = ft_insert(argc, argv);
	p = head;
	while (p)
	{
		printf("val: %d\n", *p->value);
		printf("position: %d\n", *p->position);
		printf("bin: %s\n", p->binary);
		p = p->next;
	}
	// p = head;
	// while (p)
	// {
	// 	printf("%d\n", p->value);
	// 	printf("%d\n", p->position);
	// 	printf("%s\n", p->binary);
	// 	p = p->next;
	// }
	ft_free(head);
}