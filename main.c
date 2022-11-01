/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:09 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 20:14:31 by jyildiri         ###   ########.fr       */
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
		sort_two(stacks);
	else if (nb_args == 3)
		sort_three(stacks->stack_a, stacks->stack_op);
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

int	main(int argc, char *argv[])
{
	t_infos	stacks;
	char	*buffer;

	stacks.stack_a = NULL;
	stacks.stack_b = NULL;
	stacks.stack_op = NULL;
	buffer = check_args(argc, argv);
	if (buffer == NULL)
		return (0);
	stacks.stack_a = args_to_stack(buffer);
	stacks.stack_a = simplify(stacks.stack_a,
			args_to_int(buffer, stacks.stack_a));
	if (stacks.stack_a == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
	free(buffer);
	stacks.stack_op = lstnew(sa);
	find_algo(&stacks);
	free_stack(stacks.stack_a);
	free_stack(stacks.stack_b);
	print_operations(stacks.stack_op);
	free_stack(stacks.stack_op);
	return (1);
}
