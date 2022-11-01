/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:08:11 by jyildiri          #+#    #+#             */
/*   Updated: 2021/12/21 17:43:27 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	c;
	char	*tdest;
	char	*tsource;

	if (!dst && !src)
		return (NULL);
	tdest = (char *) dst;
	tsource = (char *) src;
	c = 0;
	while (c < n)
	{
		tdest[c] = tsource[c];
		c++;
	}
	return ((void *)tdest);
}
