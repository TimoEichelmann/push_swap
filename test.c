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

int	ft_revrotate(stack_t	**stack)
{
	stack_t *lstlast;
	stack_t	*lstsectolast;
	stack_t *lstfirst;

	lstfirst = *stack;
	if (!*stack || !lstfirst->next)
		return -1;
	lstlast = ft_lstlast(*stack);
	lstsectolast = ft_lstsectolast(*stack);
	lstsectolast->next = lstlast->next;
	lstlast->next = *stack;
	*stack = lstlast;
	return (0);
}

int main(void)
{
	stack_t *head;
	head = NULL;
	printf("%d", ft_revrotate(&head));
}
