/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:46 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/04 17:21:38 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_whitespace(int c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int	is_str_empty(char *str)
{
	int	i;

	if (!str)
		return (1);
	i = -1;
	while (str[++i] != '\0')
		if (!is_whitespace(str[i]))
			return (0);
	return (1);
}

void	init_and_fill(t_stack *stack_op, int op_name)
{
	t_stack	*tmp;

	if (stack_op == NULL)
	{
		stack_op = lstnew(op_name);
		return ;
	}
	tmp = stack_op;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = lstnew(op_name);
}

void	print_operations(t_stack *stack_op)
{
	t_stack	*tmp;

	tmp = stack_op;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->content == pa)
			ft_putstr_fd("pa\n", 1);
		else if (tmp->content == pb)
			ft_putstr_fd("pb\n", 1);
		else if (tmp->content == ra)
			ft_putstr_fd("ra\n", 1);
		else if (tmp->content == rb)
			ft_putstr_fd("rb\n", 1);
		else if (tmp->content == rra)
			ft_putstr_fd("rra\n", 1);
		else if (tmp->content == rrb)
			ft_putstr_fd("rrb\n", 1);
		else if (tmp->content == sa)
			ft_putstr_fd("sa\n", 1);
		else if (tmp->content == sb)
			ft_putstr_fd("sb\n", 1);
		tmp = tmp->next;
	}
}

int	is_there_a_space(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			return (1);
		i++;
	}
	ft_putstr_fd("Error\n", 2);
	return (0);
}

void print_stack(t_stack *astack)
{
	t_stack *tmp;

	if (astack == NULL)
		return ;
	tmp = astack;
	while(tmp)
	{
		printf("%i ", tmp->content);
		tmp = tmp->next;
	}
	printf("\n");
}
