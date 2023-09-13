#include <stdio.h>
#include <stdlib.h>

// void    ft_bubblesort(int **arr, int argc)
// {
//     int    i;
//     int    j;
//     int    tmp;

//     i = 0;
//     j = 0;
//     while (i < argc)
//     {
//         while (j < (argc - i - 1))
//         {
//             if (*(*arr + j) > *(*arr + (j + 1)))
//             {
//                 tmp = *(*arr + j);
//                 *(*arr + j) = *(*arr + (j + 1));
//                 *(*arr + (j + 1)) = tmp;
//             }
//             j++;
//         }
//         i++;
//         j = 0;
//     }
// }

// int	*ft_sort(stack_t *head, int argc)
// {
// 	int	*result;
// 	int	i;

// 	i = 0;
// 	result = malloc(sizeof(int) * (argc - 1));
// 	while (head)
// 	{
// 		result[i] = head->value;
// 		head = head->next;
// 		i++;
// 	}
// 	result[i] = '\0';
// 	ft_bubblesort(&result, argc);
// 	return (result);
// }

// main
	// int		*sorted;
	// sorted = ft_sort(head, argc);
// while (p)
	// {
	// 	while (p->value != sorted[i])
	// 		i++;
	// 	p->position = i;
	// 	i = 0;
	// 	p = p->next;
	// }
	// free(sorted);
	// 
	// ft_free(head);
	// 

typedef struct stack
{
	int				*value;
	int				*position;
	char			*binary;
	struct stack*	next;
}stack_t;

void	ft_sa(stack_t **head)
{
	stack_t *stack;
	stack_t *stack1;
	stack_t *stack2;

	stack = *head;
	stack1 = stack->next;
	stack2 = stack1->next;
	if (!*head || !stack1)
		return ;
	stack1->next = stack;
	stack->next = stack2;
	*head = stack1;
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
	head = a;
	a->next = a1;
	a1->next = a2;
	a2->next = NULL;
	a->value = malloc(sizeof(int));
	a1->value = malloc(sizeof(int));
	a2->value = malloc(sizeof(int));
	*a->value = 1;
	*a1->value = 2;
	*a2->value = 3;
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	head = a;
	ft_sa(&head);
	while (head)
	{
		printf("%d\n", *head->value);
		head = head->next;
	}
	free(a->value);
	free(a1->value);
	free(a);
	free(a1);
}
