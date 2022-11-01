/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:53:40 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 20:28:47 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoli(const char *str)
{
	int			is_negativ;
	long int	number;

	number = 0;
	is_negativ = 1;
	while (*str && is_whitespace(*str))
		str++;
	if (*str && (*str == '-' || *str == '+'))
		if (*(str++) == '-')
			is_negativ = -is_negativ;
	while (*str && (*str >= '0' && *str <= '9'))
		number = number * 10 + *(str++) - 48;
	return (number * is_negativ);
}
