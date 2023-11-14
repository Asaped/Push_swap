#include "push_swap.h"

static int	is_max(int max, t_list *stack)
{
	int	i;

	i = 0;
	while (i < stack->alen)
	{
		if (max < stack->a[i])
			return (0);
		i++;
	}
	return (1);
}

static void	sort_3(t_list *stack)
{
	if (is_max(stack->a[2], stack) && !is_sorted(stack->a, stack->alen))
		sa(stack);
	else if (is_max(stack->a[0], stack) && !is_sorted(stack->a, stack->alen))
	{
		ra(stack);
		if (!is_sorted(stack->a, stack->alen))
			sa(stack);
	}
	else if (is_max(stack->a[1], stack) && !is_sorted(stack->a, stack->alen))
	{
		rra(stack);
		if (!is_sorted(stack->a, stack->alen))
			sa(stack);
	}
}

static void	sort_4(t_list *stack)
{
	if (is_max(stack->a[3], stack))
		rra(stack);
	else if (is_max(stack->a[1], stack) || is_max(stack->a[2], stack))
	{
		if (is_max(stack->a[2], stack))
			ra(stack);
		ra(stack);
	}
	pb(stack);
	sort_3(stack);
	pa(stack);
	ra(stack);
}

static void	sort_5(t_list *stack)
{
	if (is_max(stack->a[3], stack) || is_max(stack->a[4], stack))
	{
		if (is_max(stack->a[3], stack))
			rra(stack);
		rra(stack);
	}
	else if (is_max(stack->a[1], stack) || is_max(stack->a[2], stack))
	{
		if (is_max(stack->a[2], stack))
			ra(stack);
		ra(stack);
	}
	pb(stack);
	sort_4(stack);
	pa(stack);
	ra(stack);
}

void	otismo_sort(t_list *stack)
{
	if (stack->alen == 2)
		sa(stack);
	else if (stack->alen == 3)
		sort_3(stack);
	else if (stack->alen == 4)
		sort_4(stack);
	else
		sort_5(stack);
}
