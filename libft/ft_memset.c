/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 13:11:06 by jyildiri          #+#    #+#             */
/*   Updated: 2021/12/21 18:00:00 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *pointer, int value, size_t count)
{
	size_t	i;
	char	*tpointer;

	tpointer = (char *)pointer;
	i = 0;
	while (count > i)
	{
		tpointer[i] = value;
		i++;
	}
	return ((void *)tpointer);
}
