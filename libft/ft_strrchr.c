/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 11:38:18 by jyildiri          #+#    #+#             */
/*   Updated: 2021/12/26 16:47:36 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int		j;
	char	*c;

	c = (char *) s;
	j = ft_strlen(c);
	while (j > 0)
	{
		if (c[j] == (char)n)
			return (&c[j]);
		j--;
	}
	if (c[j] == (char)n)
		return (&c[j]);
	return (NULL);
}
