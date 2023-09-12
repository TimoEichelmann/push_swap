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
	int	*p;
	char *c;
}stack;
void	ft_change(stack *s)
{
	*s->p = 6;
	s->c[0] = 'a';
	s->c[1] = 's';
	s->c[2] = '\0';
	return ;
}

int main(void)
{
	stack *s;
	s = malloc(sizeof(stack));
	s->p = malloc(sizeof(int));
	s->c = malloc(sizeof(char) * 3);
	*s->p = 8;
	ft_change(s);
	printf("%d", *s->p);
	printf("%s", s->c);
	free(s->p);
	free(s);

}
