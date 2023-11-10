#include "push_swap.h"

static void	swap(int *num, int len)
{
	int	temp;

	if (len > 1)
	{
		temp = num[0];
		num[0] = num[1];
		num[1] = temp;
	}
}

void	sa(t_list *stack)
{
	swap(stack->a, stack->alen);
	write(1, "Swap stack A\n", 13);
}

void	sb(t_list *stack)
{
	swap(stack->b, stack->blen);
	write(1, "Swap stack B\n", 13);
}

void	ss(t_list *stack)
{
	swap(stack->a, stack->alen);
	swap(stack->b, stack->blen);
	write(1, "Swap stack A and B\n", 19);
}
