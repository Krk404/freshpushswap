/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 15:34:54 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 12:23:56 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_checkset(char const s1, char const *set )
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == s1)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*s2;
	int		indexstart;
	int		indexfin;
	int		i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	indexfin = ft_strlen(s1) - 1;
	indexstart = 0;
	i = 0;
	while (s1 && ft_checkset(s1[indexstart], set) == 1)
		indexstart++;
	while (indexfin >= indexstart && ft_checkset(s1[indexfin], set) == 1)
		indexfin--;
	s2 = malloc(sizeof(char) * (indexfin - indexstart) + 2);
	if (s2 == NULL)
		return (NULL);
	while (indexstart <= indexfin)
	{
		s2[i++] = s1[indexstart++];
	}
	s2[i] = '\0';
	return (s2);
}
