#include "push_swap.h"

void	reverse_rotate(int *num, int len)
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
	}
}

void	rra(t_list *stack)
{
	reverse_rotate(stack->a, stack->alen);
	write(1, "Reverse rotate stack A\n", 23);
}

void	rrb(t_list *stack)
{
	reverse_rotate(stack->b, stack->blen);
	write(1, "Reverse rotate stack A\n", 23);
}

void	rrr(t_list *stack)
{
	reverse_rotate(stack->a, stack->alen);
	reverse_rotate(stack->b, stack->blen);
	write(1, "Reverse rotate stack A and B\n", 29);
}
