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

#include "push_swap.h"

void ft_free(t_stack **head)
{
	t_stack	*p;
	t_stack *h;

	h = *head;
	while (h)
	{
		p = h->next;
		free(h->value);
		free(h->position);
		free(h->binary);
		free(h);
		h = p;
	}
	return;
}

// int	ft_atoi(const char *p)
// {
// 	int	i;
// 	int	result;
// 	int	sign;

// 	sign = 1;
// 	result = 0;
// 	i = 0;
// 	while (p[i] == ' ' || p[i] == '\f' || p[i] == '\n' || p[i] == '\r'
// 		|| p[i] == '\t' || p[i] == '\v')
// 		i++;
// 	if (p[i + 1] >= '0' && p[i + 1] <= '9' && (p[i] == '-' || p[i] == '+'))
// 	{
// 		if (p[i] == '-')
// 			sign = -1;
// 		i++;
// 	}
// 	else if ((p[i] == '-' || p[i] == '+') && !(p[i + 1] >= '0' && p[i] <= '9'))
// 		return (0);
// 	while (p[i] >= '0' && p[i] <= '9')
// 	{
// 		result = result * 10 + (p[i] - '0');
// 		i++;
// 	}
// 	return (result * sign);
// }

// t_stack	*ft_lstlast(t_stack *lst)
// {
// 	while (lst)
// 	{
// 		if (!lst->next)
// 			return (lst);
// 		lst = lst->next;
// 	}
// 	return (lst);
// }

// void	ft_lstadd_back(t_stack **lst, t_stack *new)
// {
// 	t_stack	*last;

// 	if (*lst && lst)
// 	{
// 		last = ft_lstlast(*lst);
// 		last->next = new;
// 	}
// 	else
// 		*lst = new;
// }

int    ft_bubblesort(int **arr, int argc, int swi)
{
    int    i;
    int    j;
    int    tmp;

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
	int	*result;
	int	i;
	int swi;
	t_stack *p;

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

t_stack *ft_initialize(t_stack *head, int argc)
{
	t_stack	*p;
	int		*sorted;
	int		i;

	i = 0;
	sorted = ft_sort(&head, argc - 1);
	if (!sorted)
		return NULL;
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

void	ft_strrev(char **string)
{
	int		i;
	int		j;
	char	temp;
	char	*s;

	i = 0;
	s = *string;
	j = ft_strlen(*string);
	if (j == 1)
		return;
	else
		while (i < j/2)
		{
			temp = s[i];
			s[i] = s[j-i-1];
			s[j-i-1] = temp;
			i++;
		}
}

t_stack	*ft_rev_bins(t_stack **list)
{
	t_stack *head;
	t_stack *p;

	head = *list;
	p = *list;
	while (p)
	{
		ft_strrev(&p->binary);
		p = p->next;
	}
	return(head);
}

t_stack	*ft_insert(int argc, char **argv)
{
    int    i;
    t_stack *head;
    t_stack *p;

    i = 1;
	head = NULL;
    while (i < argc)
    {
        p = malloc(sizeof(t_stack));
		p->value = malloc(sizeof(int));
		if (!p || !p->value)
			return (NULL);
        *p->value = ft_atoi(argv[i]);
        p->next = NULL;
        ft_lstadd_back(&head, p);
        i++;
    }
	if (!ft_initialize(head, argc))
		return NULL;
	head = ft_rev_bins(&head);
	return (head);
}

// int main(int argc, char **argv)
// {
// 	t_stack* head;
// 	t_stack *p;

// 	head = ft_insert(argc, argv);
// 	if (!head)
// 	{
// 		printf("%p", ft_insert(argc, argv));
// 		ft_free(head);
// 		return (0);
// 	}
// 	p = head;
// 	while (p)
// 	{
// 		printf("val: %d\n", *p->value);
// 		printf("position: %d\n", *p->position);
// 		printf("bin: %s\n", p->binary);
// 		p = p->next;
// 	}
// 	// p = head;
// 	// while (p)
// 	// {
// 	// 	printf("%d\n", p->value);
// 	// 	printf("%d\n", p->position);
// 	// 	printf("%s\n", p->binary);
// 	// 	p = p->next;
// 	// }
// 	ft_free(head);
// }