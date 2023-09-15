#include "push_swap.h"

// void	ft_sort_big(stack_t **stack_a, stack_t **stack_b, int argc)
// {
// 	stack_t *ahead;
// 	stack_t *bhead;
// 	int		i;
// 	int		j;

// 	i = 0;
// 	j = 0;
// 	ahead = *stack_a;
// 	bhead = *stack_b;
// 	printf("%d\n", ft_strlen(ft_binconvert(argc)));
// 	while (i < ft_strlen(ft_binconvert(argc)))
// 	{
// 		while (j < argc)
// 		{
// 			if (!ahead->value)
// 				j++;
// 			else
// 			{
// 				if (ahead->value[i] == '0')
// 					ft_pb(&ahead, &bhead);
// 				else
// 					ft_ra(&ahead);
// 				j++;
// 			}
// 		}
// 		i++;
// 		while (bhead)
// 			ft_pa(&ahead, &bhead);
// 	}
// 	bhead = ahead;
// 	while (ahead)
// 	{
// 		printf("value : %d\n", *ahead->value);
// 		printf("binary : %s\n", ahead->binary);
// 		ahead = ahead->next;
// 	}
// }

int main(int	argc, char **argv)
{
	stack_t *stack_a;
	stack_t *stack_b;
	// int		i;
	// i = 0;
	printf("%d\n", argc);
	stack_a = ft_insert(argc, argv);
	// printf("a :%s\n", stack_a->binary);
	// stack_b = stack_a->next;
	// printf("b :%s\n", stack_b->binary);
	// ft_sort_big(&stack_a, &stack_b, argc);
	// if (stack_b->binary[i] == '0')
	// 	printf("hello");
	stack_b = stack_a;
	while (stack_a)
	{
		printf("val :%d position : %d bin : %s\n", *stack_a->value, *stack_a->position, stack_a->binary);
		stack_a = stack_a->next;
	}
	stack_a = stack_b;
	ft_free(&stack_a);
	ft_free(&stack_b);
}
