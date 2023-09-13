#include <stdio.h>
#include <stdlib.h>

typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

void	ft_pa(stack_t **stack_a, stack_t **stack_b)
{
	stack_t *afirst;
	stack_t *bfirst;

	if (!*stack_b)
		return ;
	afirst = *stack_a;
	bfirst = *stack_b;
	*stack_b = bfirst->next;
	bfirst->next = afirst;
	*stack_a = bfirst;
}

int main(void)
{
	stack_t *ahead;
	stack_t *bhead;
	stack_t *a;
	stack_t *a1;
	// stack_t *b1;

	a = malloc(sizeof(stack_t));
	a1 = malloc(sizeof(stack_t));
	// b1 = malloc(sizeof(stack_t));
	ahead = a;
	bhead = NULL;
	a->next = a1;
	a1->next = NULL;
	// b1->next = NULL;
	a->value = malloc(sizeof(int));
	a1->value = malloc(sizeof(int));
	// b1->value = malloc(sizeof(int));
	*a->value = 1;
	*a1->value = 1;
	// *b1->value = 2;
	while (ahead)
	{
		printf("%d\n", *ahead->value);
		ahead = ahead->next;
	}
	ahead = a;
	while (bhead)
	{
		printf("%d\n", *bhead->value);
		bhead = bhead->next;
	}
	ft_pa(&ahead, &bhead);
	while (ahead)
	{
		printf("%d\n", *ahead->value);
		ahead = ahead->next;
	}
	ahead = a;
	while (bhead)
	{
		printf("%d\n", *bhead->value);
		bhead = bhead->next;
	}
	printf("%p\n", bhead);
	free(a->value);
	free(a1->value);
	free(a);
	free(a1);
}
