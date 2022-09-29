/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_parse_tools.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ael-hamd <ael-hamd@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/18 01:11:51 by ael-hamd          #+#    #+#             */
/*   Updated: 2022/09/28 22:05:23 by ael-hamd         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_countline(const char *s, char c)
{
	int		word;
	int		i;
	char	*str;

	str = (char *)s;
	word = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == c && str[i + 1])
			word++;
		i++;
	}
	return (word);
}

static char	**ft_filltab(char **tab, const char *s, char c)
{
	int	i;
	int	j;
	int	k;
	int	word;

	word = ft_countline(s, c);
	k = 0;
	i = 0;
	while (k < word)
	{
		j = 0;
		while ((s[i] && s[i] != c))
			tab[k][j++] = s[i++];
		if (s[i] == c)
			i++;
		tab[k][j] = '\0';
		k++;
	}
	tab[k] = NULL;
	return (tab);
}

static char	*ft_alloc(char	**tab, int index, int size)
{
	int	i;

	i = 0;
	tab[index] = (char *)malloc(sizeof(char) * size);
	if (!tab[index])
	{
		while (i < index)
			free(tab[i++]);
		free(tab);
		return (NULL);
	}
	return (tab[index]);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		word;

	if (!s)
		return (NULL);
	word = ft_countline(s, c);
	tab = (char **)malloc(sizeof(char *) * (word + 1));
	if (!tab)
		return (NULL);
	i = 0;
	while (word > 0)
	{
		j = 0;
		while (s[i] && s[i++] != c)
			j++;
		if (ft_alloc(tab, ft_countline(s, c) - word, j + 1) == NULL)
			return (NULL);
		word--;
	}
	return (ft_filltab(tab, s, c));
}
