#include <stdio.h>
#include <stdlib.h>




int main(void)
{
	printf("%s\n", ft_convert(6));
}

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

