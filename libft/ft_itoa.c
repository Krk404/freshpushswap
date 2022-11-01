/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:52:23 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 13:34:34 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_intlen(long int n)
{
	long int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = -n;
		len++;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*s;
	long int		i;

	i = n;
	n = ft_intlen(i);
	s = malloc(sizeof(char) * (n + 1));
	if (s == NULL)
		return (NULL);
	s[n--] = '\0';
	if (i == 0)
	{
		s[i] = '0';
		return (s);
	}
	if (i < 0)
	{
		s[0] = '-';
		i = -i;
	}
	while (i > 0)
	{
		s[n--] = i % 10 + 48;
		i = i / 10;
	}
	return (s);
}
