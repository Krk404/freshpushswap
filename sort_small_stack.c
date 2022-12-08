/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:38 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/08 14:03:47 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_values(int *tab, int i, t_stack *stack)
{
	int		n;
	t_stack	*tmp;

	tmp = stack;
	n = 0;
	while (n < i)
	{
		tab[n++] = tmp->content;
		tmp = tmp->next;
	}
}

int	get_min_pos(t_stack *stack_a)
{
	int		min_number;
	int		min_pos;
	int		index;
	t_stack	*tmp;

	min_number = stack_a->content;
	min_pos = 1;
	index = 1;
	tmp = stack_a;
	while (tmp)
	{
		if (min_number > tmp->content)
		{
			min_number = tmp->content;
			min_pos = index;
		}
		tmp = tmp->next;
		index++;
	}
	return (min_pos);
}

void	sort_two(t_infos *stacks)
{
	t_stack	*tmp;

	tmp = stacks->stack_a;
	if (tmp->content > tmp->next->content)
		swap(&tmp, stacks->stack_op, A);
}

void	sort_three(t_stack **stack_a, t_stack *stack_op)
{
	int	i[3];

	get_values(i, 3, *stack_a);
	if (i[0] < i[1] && i[1] > i[2])
	{
		if (i[0] < i[2])
		{
			swap(stack_a, stack_op, A);
			rotate(stack_a, stack_op, A);
		}
		else if (i[0] > i[2])
		{
			reverse_rotate(stack_a, stack_op, A);
		}
	}
	else if (i[0] > i[1] && i[0] > i[2])
	{
		rotate(stack_a, stack_op, A);
		if (i[1] > i[2])
			swap(stack_a, stack_op, A);
	}
	else if (i[0] > i[1] && i[0] < i[2] && i[1] < i[2])
		swap(stack_a, stack_op, A);
}

void	sort_small_stack(t_infos *stacks)
{
	int	position;
	int	nb_args;

	while (!a_is_sorted(stacks->stack_a))
	{
		nb_args = count(stacks->stack_a);
		position = get_min_pos(stacks->stack_a);
		if (nb_args == 3)
		{
			sort_three(&stacks->stack_a, stacks->stack_op);
			continue ;
		}
		if (position == 1)
		{
			push(&stacks->stack_a, &stacks->stack_b, stacks->stack_op, A);
			continue ;
		}
		if (position <= nb_args / 2)
			rotate(&stacks->stack_a, stacks->stack_op, A);
		else
			reverse_rotate(&stacks->stack_a, stacks->stack_op, A);
	}
	while (stacks->stack_b != NULL)
		push(&stacks->stack_b, &stacks->stack_a, stacks->stack_op, B);
}
