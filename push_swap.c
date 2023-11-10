#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	stack;

	if (ac > 1)
	{
		if (!ft_tabini(&stack, av + 1, --ac, 0))
		{
			printf("bruh\n");
			return (0);
		}
		int	i = 0;
		pb(&stack);
		printf("alen = %d\n", stack.alen);
		while (stack.a[i])
		{
			printf("numA[%d] = %d\n", i, stack.a[i]);
			i++;
		}
		i = 0;
		printf("\n");
		printf("blen = %d\n", stack.blen);
		while (stack.b[i])
		{
			printf("numB[%d] = %d\n", i, stack.b[i]);
			i++;
		}
	}
	else
		return (0);
}
