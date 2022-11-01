/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:15 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 16:54:22 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	do_bitshifting(t_infos *stacks, int i, int size)
{
	int	j;
	int	num;

	j = 0;
	while (j++ < size)
	{
		num = stacks->stack_a->content;
		if (((num >> i) & 1) == 1)
			rotate(&stacks->stack_a, stacks->stack_op, A);
		else
			push(&stacks->stack_a, &stacks->stack_b, stacks->stack_op, A);
	}
}

void	radix_sort(t_infos *stacks)
{
	int	size;
	int	max_num;
	int	max_bits;
	int	i;

	i = 0;
	size = count(stacks->stack_a);
	max_num = size - 1;
	max_bits = 0;
	while ((max_num >> max_bits) != 0)
		++max_bits;
	while (i < max_bits)
	{
		do_bitshifting(stacks, i, size);
		while (stacks->stack_b != NULL)
			push(&stacks->stack_b, &stacks->stack_a, stacks->stack_op, B);
		i++;
	}
}
