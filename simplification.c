/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simplification.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 17:42:06 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/08 14:27:50 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*simplify(t_stack *a_stack, int *tab_int)
{
	int		index;
	int		n;
	t_stack	*tmp;

	tmp = a_stack;
	n = count(a_stack);
	index = 0;
	while (tmp && index < n)
	{
		tmp->content = tab_simplifier(tab_int, index, n);
		tmp = tmp->next;
		index++;
	}
	if (dupes_checker(tab_int, n) == 0)
	{
		free(tab_int);
		free_stack(a_stack);
		return (NULL);
	}
	free(tab_int);
	return (a_stack);
}

int	dupes_checker(int *tab_int, int args_numb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < args_numb)
	{
		while (j < args_numb)
		{
			if (tab_int[j] == tab_int[i] && i != j)
				return (0);
			j++;
		}
		j = 0;
		i++;
	}
	return (1);
}

int	count(t_stack *a_stack)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	tmp = a_stack;
	if (tmp == NULL)
		return (0);
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}

int	*args_to_int(char *str, t_stack *a_stack)
{
	char	**tab_char;
	int		*tab_int;
	int		i;

	i = 0;
	if (str == NULL)
		return (NULL);
	tab_char = ft_split(str, ' ');
	tab_int = malloc(sizeof(int) * count(a_stack));
	while (tab_char[i])
	{
		tab_int[i] = ft_atoi(tab_char[i]);
		i++;
	}
	ft_freetab(tab_char);
	return (tab_int);
}

int	tab_simplifier(int *tab, int index, int n)
{
	int	counter;
	int	i;

	i = 0;
	counter = 0;
	while (i < n)
	{
		if (tab[index] > tab[i])
			counter++;
		i++;
	}
	return (counter);
}
