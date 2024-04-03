/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:58 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 11:30:26 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	min_target(t_stack *a, t_stack *b)
{
	int		min;
	t_stack	*tmp;

	while (a)
	{
		min = INT_MIN;
		tmp = b;
		a->target = get_max_node(b);
		while (tmp)
		{
			if (a->num > tmp->num && tmp->num >= min)
			{
				min = tmp->num;
				a->target = tmp;
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}

static void	max_target(t_stack *b, t_stack *a)
{
	int		max;
	t_stack	*tmp;

	while (b)
	{
		max = INT_MAX;
		tmp = a;
		b->target = get_min_node(a);
		while (tmp)
		{
			if (b->num < tmp->num && tmp->num <= max)
			{
				max = tmp->num;
				b->target = tmp;
			}
			tmp = tmp->next;
		}
		b = b->next;
	}
}

static void	stack_a_in_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*node_tmp;

	node_tmp = get_node_min_move(*a);
	if (node_tmp->above_median == node_tmp->target->above_median)
	{
		if (node_tmp->above_median)
			while (*a != node_tmp && *b != node_tmp->target)
				rr(a, b);
		else
			while (*a != node_tmp && *b != node_tmp->target)
				rrr(a, b);
	}
	min_move_on_top(a, node_tmp, 1);
	min_move_on_top(b, node_tmp->target, 0);
	pb(a, b);
}

static void	stack_b_in_stack_a(t_stack **a, t_stack **b)
{
	min_move_on_top(a, (*b)->target, 1);
	pa(a, b);
}

void	sort(t_stack **a, t_stack **b, int five)
{
	int	i;
	int	len;

	i = 0;
	len = stack_len(*a);
	while (i++ < 2 && len-- > 3 && !is_sort_list(*a))
		pb(a, b);
	while (len-- > 3 && !is_sort_list(*a))
	{
		set_post(*a);
		set_post(*b);
		min_target(*a, *b);
		set_min_mov(*a, *b);
		stack_a_in_stack_b(a, b);
	}
	sort_three(a);
	while (*b)
	{
		set_post(*a);
		set_post(*b);
		max_target(*b, *a);
		stack_b_in_stack_a(a, b);
	}
	move_min_on_top(a, five);
}
