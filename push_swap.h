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
}				t_list;


char	**ft_split(char const *s, char c);

int		ft_tabini(t_list *stack, char **av, int ac);

size_t	ft_tablen(char **tab);

size_t	ft_strlen(char *str);

#endif
