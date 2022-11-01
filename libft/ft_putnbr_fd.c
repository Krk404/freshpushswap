/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 15:18:58 by jyildiri          #+#    #+#             */
/*   Updated: 2021/12/21 18:03:29 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long int	n2;

	n2 = n;
	if (n2 < 0)
	{
		n2 = n2 * (-1);
		ft_putchar_fd('-', fd);
	}
	if (n2 >= 10)
	{
		ft_putnbr_fd(n2 / 10, fd);
		ft_putchar_fd((n2 % 10) + 48, fd);
	}
	if (n2 < 10)
	{
		ft_putchar_fd((n2 % 10) + 48, fd);
	}
}
