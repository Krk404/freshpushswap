/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:12 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 16:54:20 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack, t_stack *stack_op, int stack_name)
{
	t_stack	*tmp;
	int		help;

	if (stack == NULL)
		return ;
	tmp = *stack;
	help = tmp->content;
	tmp->content = tmp->next->content;
	tmp->next->content = help;
	if (stack_name == A)
		init_and_fill(stack_op, sa);
	else if (stack_name == B)
		init_and_fill(stack_op, sb);
}

void	rotate(t_stack **stack, t_stack *stack_op, int stack_name)
{
	t_stack	*tmp;
	int		first;

	if (stack == NULL)
		return ;
	tmp = *stack;
	first = tmp->content;
	while (tmp->next)
	{
		tmp->content = tmp->next->content;
		tmp = tmp->next;
	}
	tmp->content = first;
	if (stack_name == A)
		init_and_fill(stack_op, ra);
	else if (stack_name == B)
		init_and_fill(stack_op, rb);
}

void	reverse_rotate(t_stack **stack, t_stack *stack_op, int stack_name)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = *stack;
	while (stack_a->next->next)
		stack_a = stack_a->next;
	tmp = stack_a->next;
	stack_a->next = NULL;
	tmp->next = *stack;
	*stack = tmp;
	if (stack_name == A)
		init_and_fill(stack_op, rra);
	else if (stack_name == B)
		init_and_fill(stack_op, rrb);
}

void	push(t_stack **stack_from, t_stack **stack_to, t_stack *stack_op,
		int stack_name)
{
	t_stack	*tmp_from;
	t_stack	*tmp_final;

	if (*stack_from == NULL)
		return ;
	tmp_from = *stack_from;
	tmp_final = lstnew(tmp_from->content);
	*stack_from = tmp_from->next;
	free(tmp_from);
	tmp_final->next = *stack_to;
	*stack_to = tmp_final;
	if (stack_name == A)
		init_and_fill(stack_op, pb);
	else if (stack_name == B)
		init_and_fill(stack_op, pa);
}
