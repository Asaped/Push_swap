#include "push_swap.h"

static int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

static long int	ft_atoi(char *str)
{
	long int	res;
	int			neg;

	res = 0;
	neg = 1;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	while (*str && *str >= '0' && *str <= '9')
	{
		res *= 10;
		res += (*str++ - 48);
	}
	return (res * neg);
}

static int	check_list(char **tab, int ac, int i, int j)
{
	while (tab[i])
	{
		while (tab[i][j])
		{
			if (ac > 1 && tab[i][j] && (tab[i][j] == '-' && j == 0
				&& ft_isdigit(tab[i][j + 1])) || ft_isdigit(tab[i][j]))
				j++;
			else if (ac == 1 && tab[i][j] && (ft_isdigit(tab[i][j])
				|| (tab[i][j] == ' ' && j != 0 && j + 1 != ft_strlen(tab[i])
				&& tab[i][j - 1] != ' ' && tab[i][j + 1] != ' ')
				|| (tab[i][j] == '-' && ft_isdigit(tab[i][j + 1])
				&& (j == 0 || tab[i][j - 1] == ' '))))
				j++;
			else
				return (0);
		}
		if (j == 0)
			return (0);
		j = 0;
		i++;
	}
	return (1);
}

static int	ft_free(t_list *stack, int ac)
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
		{
			free(stack->tab[i]);
			i++;
		}
		if (stack->tab)
			free(stack->tab);
	}
	return (0);
}

static int	no_double(int *a, int ac)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (i < ac)
	{
		while (j < ac)
		{
			if (a[i] == a[j])
				return (0);
			j++;
		}
		i++;
		j = i + 1;
	}
	return (1);
}

static int	is_sorted(int *a, int len)
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

int	ft_tabini(t_list *stack, char **av, int ac)
{
	int			count;
	long int	res;

	if (!check_list(av, ac, 0, 0))
		return (0);
	if (ac == 1)
		stack->tab = ft_split(av[0], ' ');
	else
		stack->tab = av;
	stack->alen = ft_tablen(stack->tab);
	count = ft_tablen(stack->tab);
	stack->a = malloc(sizeof(int) * count);
	stack->b = malloc(sizeof(int) * count);
	if (!stack->a || !stack->b)
		return (ft_free(stack, ac));
	while (--count >= 0)
	{
		res = ft_atoi(stack->tab[count]);
		if (res > 2147483647 || res < -2147483648)
			return (ft_free(stack, ac));
		stack->a[count] = (int)res;
	}
	if (!no_double(stack->a, stack->alen) || is_sorted(stack->a, stack->alen))
		return (ft_free(stack, ac));
	return (1);
}
