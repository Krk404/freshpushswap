/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:42 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/06 17:49:44 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*args_to_stack(char *str)
{
	char	**tab;
	int		i;
	t_stack	*stack_a;
	t_stack	*stack_tmp;

	i = 0;
	stack_a = malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (NULL);
	tab = ft_split(str, ' ');
	stack_a->content = ft_atoi(tab[i]);
	i++;
	stack_tmp = stack_a;
	while (tab[i] != NULL)
	{
		stack_tmp->next = lstnew(ft_atoi(tab[i]));
		i++;
		stack_tmp = stack_tmp->next;
	}
	ft_freetab(tab);
	return (stack_a);
}

t_stack	*lstnew(int content)
{
	t_stack	*nl;

	nl = malloc(sizeof(t_stack));
	if (nl == NULL)
		return (NULL);
	nl->content = content;
	nl->next = NULL;
	return (nl);
}
