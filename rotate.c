#include "push_swap.h"

int	rotate(int *num, int len)
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
		return (1);
	}
	return (0);
}

void	ra(t_list *stack)
{
	if (rotate(stack->a, stack->alen))
		write(1, "ra\n", 3);
}

void	rb(t_list *stack)
{
	if (rotate(stack->b, stack->blen))
		write(1, "rb\n", 3);
}

void	rr(t_list *stack)
{
	if (rotate(stack->a, stack->alen) || rotate(stack->b, stack->blen))
		write(1, "rr\n", 21);
}
