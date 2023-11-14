#include "push_swap.h"

static int	push(int *give, int *take, int *glen, int *tlen)
{
	int	temp;

	if (*glen > 0)
	{
		temp = give[0];
		rotate(give, *glen);
		*glen -= 1;
		give[*glen] = 0;
		take[*tlen] = temp;
		*tlen += 1;
		reverse_rotate(take, *tlen);
		return (1);
	}
	return (0);
}

void	pa(t_list *stack)
{
	if (push(stack->b, stack->a, &stack->blen, &stack->alen))
		write(1, "pa\n", 3);
}

void	pb(t_list *stack)
{
	if (push(stack->a, stack->b, &stack->alen, &stack->blen))
		write(1, "pb\n", 3);
}
