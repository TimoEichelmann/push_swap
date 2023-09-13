#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

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

void	ft_rotate(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstfirst;

	lstlast = ft_lstlast(*stack);
	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	*stack = lstfirst->next;
	lstfirst->next = lstlast->next;
	lstlast->next = lstfirst;
}

int main(void)
{
	stack_t *head;
	stack_t *a;
	stack_t *a1;
	stack_t *a2;

	a = malloc(sizeof(stack_t));
	a1 = malloc(sizeof(stack_t));
	a2 = malloc(sizeof(stack_t));
	a->next = a1;
	a1->next = a2;
	a2->next = NULL;
	a->value = malloc(sizeof(int));
	a1->value = malloc(sizeof(int));
	a2->value = malloc(sizeof(int));
	*a->value = 1;
	*a1->value = 2;
	*a2->value = 3;
	head = a;
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	head = a;
	ft_rotate(&head);
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	head = a;
	printf("%p", a->next);
	free(a->value);
	free(a1->value);
	free(a2->value);
	free(a);
	free(a1);
	free(a2);
}

-----------
typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

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

stack_t	*ft_lstsectolast(stack_t *lst)
{
	stack_t *next;

	while (lst)
	{
		next = lst->next;
		if (!next->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

void	ft_revrotate(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstsectolast;
	stack_t *lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return ;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
}

int main(void)
{
	stack_t *head;
	stack_t *a;
	stack_t *a1;
	stack_t *a2;

	a = malloc(sizeof(stack_t));
	a1 = malloc(sizeof(stack_t));
	a2 = malloc(sizeof(stack_t));
	a->next = a1;
	a1->next = a2;
	a2->next = NULL;
	a->value = malloc(sizeof(int));
	a1->value = malloc(sizeof(int));
	a2->value = malloc(sizeof(int));
	*a->value = 1;
	*a1->value = 2;
	*a2->value = 3;
	head = a;
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	head = a;
	ft_revrotate(&head);
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	head = a;
	printf("%p", a1->next);
	free(a->value);
	free(a1->value);
	free(a2->value);
	free(a);
	free(a1);
	free(a2);
}