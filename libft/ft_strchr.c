/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 16:56:18 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 13:32:00 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int n)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)n)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == n)
		return ((char *)&s[i]);
	return (NULL);
}
