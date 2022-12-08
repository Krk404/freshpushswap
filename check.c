/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:53:57 by jyildiri          #+#    #+#             */
/*   Updated: 2022/12/08 15:29:04 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_only_space(char **argv)
{
	int	i;
	int	n;

	i = 1;
	while (argv[i] != NULL)
	{
		n = 0;
		while (argv[i][n] != '\0')
		{
			if (!is_whitespace(argv[i][n]))
				return (0);
			n++;
		}
		i++;
	}
	return (1);
}

char	*check_args(int argc, char **argv, int j)
{
	char	*str;

	str = NULL;
	if (argc < 2)
		return (NULL);
	if (is_only_space(argv))
		return (NULL);
	if (argc == 2)
	{
		if (!is_there_a_space(argv[1]))
		{
			ft_putstr_fd("Error\n", 2);
			return (NULL);
		}
	}
	while (argv[++j])
	{
		str = ft_strjoin(str, argv[j]);
		str = ft_strjoin(str, " ");
	}
	if (check_str(str))
		return (str);
	ft_putstr_fd("Error\n", 2);
	free(str);
	return (NULL);
}

int	ft_argslen(int argc, char **argv)
{
	int	len;
	int	i;

	i = 1;
	len = 0;
	while (i < argc)
	{
		len = len + ft_strlen(argv[i]);
		i++;
	}
	return (len);
}

int	check_str(char *argv)
{
	int	i;
	int	n;

	if (is_str_empty(argv))
		return (0);
	i = 0;
	n = ft_strlen(argv);
	while (i < n)
	{
		if (ft_checknbr(argv[i]))
			i++;
		else
			return (0);
	}
	i = 0;
	while (i < n - 1)
	{
		if ((argv[i] == '-') && !ft_isdigit(argv[i + 1]))
			return (0);
		i++;
	}
	if (ft_atoli(argv) > 2147483647 || ft_atoli(argv) < -2147483648)
		return (0);
	return (1);
}
