#include "push_swap.h"

static int	swap(int *num, int len)
{
	int	temp;

	if (len > 1)
	{
		temp = num[0];
		num[0] = num[1];
		num[1] = temp;
		return (1);
	}
	return (0);
}

void	sa(t_list *stack)
{
	if (swap(stack->a, stack->alen))
		write(1, "sa\n", 3);
}

void	sb(t_list *stack)
{
	if (swap(stack->b, stack->blen))
		write(1, "sb\n", 3);
}

void	ss(t_list *stack)
{
	if (swap(stack->a, stack->alen) || swap(stack->b, stack->blen))
		write(1, "ss\n", 3);
}
