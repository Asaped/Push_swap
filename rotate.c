#include "push_swap.h"

void	rotate(int *num, int len)
{
	int	temp;
	int	i;

	i = 0;
	if (len > 1)
	{
		temp = num[0];
		while (i + 1 < len)
		{
			num[i] = num[i + 1];
			i++;
		}
		num[i] = temp;
	}
}

void	ra(t_list *stack)
{
	rotate(stack->a, stack->alen);
	write(1, "Rotate stack A\n", 15);
}

void	rb(t_list *stack)
{
	rotate(stack->b, stack->blen);
	write(1, "Rotate stack B\n", 15);
}

void	rr(t_list *stack)
{
	rotate(stack->a, stack->alen);
	rotate(stack->b, stack->blen);
	write(1, "Rotate stack A and B\n", 21);
}
