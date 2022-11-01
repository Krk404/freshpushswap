/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 14:16:09 by jyildiri          #+#    #+#             */
/*   Updated: 2021/12/21 17:42:39 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tdest;
	unsigned char	*tsource;

	if (!dest && !src)
		return (NULL);
	tdest = (unsigned char *) dest;
	tsource = (unsigned char *) src;
	i = 0;
	if (tdest > tsource)
	{
		while (n-- > 0)
			tdest[n] = tsource[n];
	}
	else
	{
		while (n > i)
		{
			tdest[i] = tsource[i];
			i++;
		}
	}
	return (dest);
}
