/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 18:35:35 by jyildiri          #+#    #+#             */
/*   Updated: 2022/10/25 14:09:36 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	comptemots(char const *s, char c)
{
	int	swap;
	int	i;
	int	compteur;

	i = 0;
	swap = -1;
	compteur = 0;
	while (s[i])
	{
		if (swap == -1 && s[i] != c)
		{
			swap = 0;
			compteur++;
		}
		else if (s[i] == c)
			swap = -1;
		i++;
	}
	return (compteur);
}

char	**freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (NULL);
}

static char	*ft_word(char **tab, char const *s, int fin, int index)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(sizeof(char) * (fin - index + 1));
	if (!word)
	{
		freetab(tab);
		return (0);
	}
	while (index < fin)
	{
		word[i] = s[index];
		i++;
		index++;
	}
	word[i] = '\0';
	return (word);
}

char	**check(char const *s, char c)
{
	char	**tab;

	if (!s)
		return (0);
	tab = malloc(sizeof(char *) * (comptemots(s, c) + 1));
	if (!tab)
		return (0);
	return (tab);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	size_t	i;
	size_t	j;
	int		index;

	tab = check(s, c);
	if (tab == NULL)
		return (0);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (index < 0 && s[i] != c)
			index = i;
		else if (index >= 0 && (i == ft_strlen(s) || s[i] == c))
		{
			tab[j++] = ft_word(tab, s, i, index);
			index = -1;
		}
	}
	tab[j] = 0;
	return (tab);
}
