/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:58 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/27 17:58:26 by cgaratej         ###   ########.fr       */
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
		a->target = max_node(b);
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

/*static void	max_target(t_stack *a, t_stack *b)
{
	int		max;
	t_stack	*tmp;

	while (a)
	{
		max = INT_MAX;
		tmp = b;
		a->target = min_node(b);
		while (tmp)
		{
			if (a->num < tmp->num && tmp->num <= max)
			{
				max = tmp->num;
				a->target = tmp;
			}
			tmp = tmp->next;
		}
		a = a->next;
	}
}*/
static void	stack_a_in_stack_b(t_stack **a, t_stack **b)
{
	t_stack	*node_tmp;

	node_tmp = get_node_min_move(*a);
	if (node_tmp->above_median == node_tmp->target->above_median)
	{
		if (node_tmp->above_median)
			while (*a != node_tmp && *b != node_tmp->target)
				rr(a, b, 0);
		else
			while (*a != node_tmp && *b != node_tmp->target)
				rrr(a, b, 0);
	}
	node_min_move_top(a, node_tmp, 1);
	node_min_move_top(a, node_tmp->target, 0);
	pb(a, b, 0);
}

void	sort(t_stack **a, t_stack **b, int len)
{
	int	i;

	i = 0;
	while (i++ < 2 && len-- > 3 && !is_sort_list(*a))
		pb(a, b, 0);
	while (len-- > 3 && !is_sort_list(*a))
	{
		set_post(*a);
		set_post(*b);
		min_target(*a, *b);
		set_min_mov(*a, *b);
	}
	sort_three(a);
}
