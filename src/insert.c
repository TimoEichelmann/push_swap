/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teichelm <teichelm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 00:18:15 by marvin            #+#    #+#             */
/*   Updated: 2025/11/19 14:30:44 by teichelm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"


void	ft_free(t_stack **head, int i)
{
	t_stack	*p;
	t_stack	*h;

	h = *head;
	while (h)
	{
		p = h->next;
		free(h->value);
		if (i != 1)
		{
			free(h->position);
			free(h->binary);
		}
		free(h);
		h = p;
	}
	return ;
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
		return ;
	else
	{
		while (i < (j / 2))
		{
			temp = s[i];
			s[i] = s[j - i - 1];
			s[j - i - 1] = temp;
			i++;
		}
	}
}

t_stack	*ft_rev_bins(t_stack **list)
{
	t_stack	*head;
	t_stack	*p;

	head = *list;
	p = *list;
	while (p)
	{
		ft_strrev(&p->binary);
		p = p->next;
	}
	return (head);
}

t_stack	*ft_insert(int argc, char **argv)
{
	int		i;
	t_stack	*head;
	t_stack	*p;

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
	if (ft_initialize(head, argc))
		return (ft_rev_bins(&head));
	ft_free(&head, 1);
	return (NULL);
}
