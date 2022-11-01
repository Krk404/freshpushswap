/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 14:23:06 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 12:15:04 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*new;
	size_t	i;

	if (s == NULL || start > ft_strlen(s))
		return (ft_strdup(""));
	i = 0;
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	new = malloc(sizeof(char) * len + 1);
	if (new == 0)
		return (NULL);
	while (i < len)
	{
		new[i] = (unsigned char)s[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}
