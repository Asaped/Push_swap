#include "push_swap.h"

static void	push(int *give, int *take, int *glen, int *tlen)
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
	}
}

void	pa(t_list *stack)
{
	push(stack->b, stack->a, &stack->blen, &stack->alen);
	write(1, "Push stack A\n", 13);
}

void	pb(t_list *stack)
{
	push(stack->a, stack->b, &stack->alen, &stack->blen);
	write(1, "Push stack B\n", 13);
}
