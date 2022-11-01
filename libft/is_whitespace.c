/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_whitespace.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 19:53:26 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 20:28:38 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_whitespace(int c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}