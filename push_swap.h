#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_list
{
	int		*a;
	int		*b;
	char	**tab;
	int		alen;
	int		blen;
}				t_list;

char	**ft_split(char const *s, char c);

int		ft_tabini(t_list *stack, char **av, int ac, long int res);

size_t	ft_tablen(char **tab);

int		ft_strlen(char *str);

int		ft_free(t_list *stack, int ac);

int		ft_isdigit(char c);

void	rotate(int *num, int len);

void	ra(t_list *stack);

void	rb(t_list *stack);

void	rr(t_list *stack);

void	sa(t_list *stack);

void	sb(t_list *stack);

void	ss(t_list *stack);

void	pa(t_list *stack);

void	pb(t_list *stack);

void	reverse_rotate(int *num, int len);

void	rra(t_list *stack);

void	rrb(t_list *stack);

void	rrr(t_list *stack);

#endif
