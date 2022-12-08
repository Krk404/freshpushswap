/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:09 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/08 15:28:48 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_algo(t_infos *stacks)
{
	int	nb_args;

	nb_args = count(stacks->stack_a);
	if (a_is_sorted(stacks->stack_a))
		return ;
	if (nb_args == 2)
	{
		sort_two(stacks);
	}
	else if (nb_args == 3)
	{
		sort_three(&(stacks->stack_a), stacks->stack_op);
	}
	else if (nb_args > 3 && nb_args < 40)
		sort_small_stack(stacks);
	else if (nb_args >= 40)
	{
		radix_sort(stacks);
		return ;
	}
}

void	ft_freetab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*next;

	tmp = stack;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
}

static int	check_main_errors(char *buffer, t_stack *stack_a)
{
	int	*tab;

	tab = args_to_int(buffer, stack_a);
	if (!dupes_checker(tab, count(stack_a)))
	{
		free(tab);
		free(buffer);
		free_stack(stack_a);
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	free(tab);
	if (a_is_sorted(stack_a))
	{
		free(buffer);
		free_stack(stack_a);
		return (1);
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_infos	stacks;
	char	*buffer;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.stack_op = NULL;
	buffer = check_args(argc, argv, 0);
	if (buffer == NULL)
		return (1);
	stacks.stack_a = args_to_stack(buffer);
	if (check_main_errors(buffer, stacks.stack_a))
		return (1);
	stacks.stack_a = simplify(stacks.stack_a,
			args_to_int(buffer, stacks.stack_a));
	free(buffer);
	if (stacks.stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	stacks.stack_op = lstnew(10);
	find_algo(&stacks);
	print_operations(stacks.stack_op);
	free_stacks(stacks);
	return (0);
}
