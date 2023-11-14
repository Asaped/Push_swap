#include "push_swap.h"

int	reverse_rotate(int *num, int len)
{
	int	i;
	int	temp;

	if (len > 1)
	{
		i = len;
		temp = num[len - 1];
		while (--i > 0)
			num[i] = num[i - 1];
		num[0] = temp;
		return (1);
	}
	return (0);
}

void	rra(t_list *stack)
{
	if (reverse_rotate(stack->a, stack->alen))
		write(1, "rra\n", 4);
}

void	rrb(t_list *stack)
{
	if (reverse_rotate(stack->b, stack->blen))
		write(1, "rrb\n", 4);
}

void	rrr(t_list *stack)
{
	if (reverse_rotate(stack->a, stack->alen)
		|| reverse_rotate(stack->b, stack->blen))
		write(1, "rrr\n", 4);
}
