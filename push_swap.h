/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyildiri <jyildiri@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/01 16:54:18 by jyildiri          #+#    #+#             */
/*   Updated: 2022/11/01 20:37:13 by jyildiri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define PA	1

# include <stdio.h>
# include "libft/libft.h"

enum	e_operations {
	pa = 0,
	pb,
	ra,
	rb,
	rra,
	rrb,
	sa,
	sb,
	A,
	B
};

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
}			t_stack;

typedef struct s_infos	t_infos;

struct	s_infos
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_stack	*stack_op;
};

char	*check_args(int argc, char **argv);

int		ft_checknbr(char c);
int		check_str(char *argv);
int		ft_argslen(int argc, char **argv);
int		count(t_stack *a_stack);
int		*args_to_int(char *str, t_stack *a_stack);
int		tab_simplifier(int *tab, int index, int n);
int		get_min_pos(t_stack *stack_a);
int		a_is_sorted(t_stack *stack_a);
int		dupes_checker(int *tab_int, int args_numb);
int		is_str_empty(char *str);
int		is_whitespace(int c);
int		is_there_a_space(char *str);

void	swap(t_stack **stack, t_stack *stack_op, int stack_name);
void	rotate(t_stack **stack, t_stack *stack_op, int stack_name);
void	reverse_rotate(t_stack **stack, t_stack *stack_op, int stack_name);
void	push(t_stack **stack_from, t_stack **stack_to, t_stack *stack_op,
			int stack_name);
void	find_algo(t_infos *stacks);
void	sort_three(t_stack *stack_a, t_stack *stack_op);
void	sort_two(t_infos *stacks);
void	get_values(int *tab, int i, t_stack *stack);
void	sort_small_stack(t_infos *stacks);
void	radix_sort(t_infos *stacks);
void	init_and_fill(t_stack *stack_op, int op_name);
void	print_operations(t_stack *stack_op);
void	ft_freetab(char **tab);
t_stack	*args_to_stack(char *str);
t_stack	*lstnew(int content);
t_stack	*simplify(t_stack *a_stack, int *tab_int);

#endif
