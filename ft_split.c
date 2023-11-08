#include "push_swap.h"

static size_t	count_word(char const *s, char c, size_t i, size_t count)
{
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i] != c && s[i])
			count++;
		while (s[i] != c && s[i])
			i++;
	}
	return (count);
}

static size_t	word_length(char const *s, char c, size_t i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

static char	*set_word(char const *s, char c, size_t i, size_t j)
{
	char	*str;

	str = malloc(sizeof(*str) * (word_length(s, c, 0) + 1));
	if (!str)
		return (NULL);
	while (s[j] != c && s[j])
		str[i++] = s[j++];
	str[i] = 0;
	return (str);
}

static char	**ft_free(char **tab, int i)
{
	while (--i >= 0)
		free(tab[i]);
	free(tab);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	count;

	if (!s)
		return (NULL);
	count = count_word(s, c, 0, 0);
	tab = malloc(sizeof(*tab) * (count + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (i < count)
	{
		while (*s == c && *s)
			s++;
		tab[i++] = set_word(s, c, 0, 0);
		if (!tab[i - 1])
			return (ft_free(tab, i));
		while (*s != c && *s)
			s++;
	}
	tab[i] = NULL;
	return (tab);
}
