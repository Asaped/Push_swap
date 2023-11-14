#include "push_swap.h"

int	main(int ac, char **av)
{
	t_list	stack;

	if (ac > 1)
	{
		if ((ac == 2 && !av[1][0]) || !ft_tabini(&stack, av + 1, --ac, 0))
			return (0);
		if (is_sorted(stack.a, stack.alen))
		{
			ft_free(&stack, ac);
			return (0);
		}
		if (stack.alen <= 5)
			otismo_sort(&stack);
		else
			sort_radix(&stack);
		ft_free(&stack, ac);
	}
	return (0);
}
