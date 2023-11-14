#include "push_swap.h"

int	is_sorted(const int *a, const int len)
{
	int	i;

	i = 0;
	while (i + 1 < len)
	{
		if (a[i] > a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

size_t	ft_tablen(char **tab)
{
	size_t	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_free(t_list *stack, int ac)
{
	int	i;

	i = 0;
	if (stack->alen > 0 || stack->blen > 0)
	{
		free(stack->a);
		free(stack->b);
	}
	if (ac == 1)
	{
		while (stack->tab[i])
			free(stack->tab[i++]);
		if (stack->tab)
			free(stack->tab);
	}
	return (0);
}

int	ft_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}
