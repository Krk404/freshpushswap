/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 16:52:27 by jyildiri          #+#    #+#             */
/*   Updated: 2022/01/03 13:33:07 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	long int	i;
	long int	signe;
	long int	somme;

	i = 0;
	signe = 1;
	somme = 0;
	while ((str[i] > 6 && str[i] < 14) || str[i] == ' ')
		i++;
	if (str[i] == 45 || str[i] == 43)
	{
		if (str[i] == 45)
			signe = signe * (-1);
		i++;
	}
	while (str[i] > 47 && str[i] < 58)
	{
		somme = somme * 10 + (str[i] - '0');
		i++;
	}
	return (somme * signe);
}
