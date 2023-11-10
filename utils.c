#include "push_swap.h"

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
	if (ac == 1)
	{
		if (stack->a)
			free(stack->a);
		if (stack->b)
			free(stack->b);
		while (stack->tab[i])
			free(stack->tab[i++]);
		if (stack->tab)
			free(stack->tab);
	}
	return (0);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
