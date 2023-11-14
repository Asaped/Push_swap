#include "push_swap.h"

static void	simplify_stack(t_list *stack, int i, int j, int k)
{
	int	*temp;

	temp = malloc(sizeof(int) * stack->alen);
	if (!temp)
		return ;
	while (++i < stack->alen)
	{
		k = 0;
		j = -1;
		while (++j < stack->alen)
		{
			if (stack->a[i] > stack->a[j])
				k++;
			temp[i] = k;
		}
	}
	i = 0;
	while (i < stack->alen)
	{
		stack->a[i] = temp[i];
		i++;
	}
	free(temp);
}

static int	get_largest_bit(t_list *stack)
{
	int		i;
	int		j;

	i = 31;
	while (i >= 0)
	{
		j = -1;
		while (++j < stack->alen)
			if ((stack->a[j] & 1 << i) == 1 << i)
				return (i);
		i--;
	}
	return (0);
}

void	sort_radix(t_list *stack)
{
	int	count;
	int	t;
	int	i;
	int	j;

	t = stack->alen;
	i = 0;
	simplify_stack(stack, -1, -1, 0);
	count = get_largest_bit(stack);
	while (i <= count)
	{
		j = -1;
		while (++j < t && !is_sorted(stack->a, stack->alen))
		{
			if (((stack->a[0] >> i) & 1) == 1)
				ra(stack);
			else
				pb(stack);
		}
		while (stack->blen)
			pa(stack);
		i++;
	}
}
