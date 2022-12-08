/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   security.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 14:02:38 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/08 15:27:09 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checknbr(char c)
{
	if ((c > 47 && c < 58) || c == ' ' || c == '-' || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

int	a_is_sorted(t_stack *stack_a)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp->next)
	{
		if (tmp->content > tmp->next->content)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_there_a_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
			return (1);
		i++;
	}
	return (0);
}

void	free_stacks(t_infos stacks)
{
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	free_stack(stacks.stack_op);
}
