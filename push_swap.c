#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	stack;

	if (ac > 1)
	{
		if (!ft_tabini(&stack, av + 1, --ac))
		{
			printf("bruh\n");
			return (0);
		}
		int i = 0;
		while (stack.a[i])
		{
			printf("num[%d] = %d\n", i, stack.a[i]);
			i++;
		}
	}
	else
		return (0);
}
