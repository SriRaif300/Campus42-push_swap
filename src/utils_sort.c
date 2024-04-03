/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 11:30:59 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	max = get_max_node(*a)->num;
	if ((*a)->num == max)
		ra(a);
	else if ((*a)->next->num == max)
		rra(a);
	if ((*a)->next->num < (*a)->num)
		sa(a);
}

void	set_post(t_stack *stack)
{
	int	median;
	int	i;

	i = 0;
	median = stack_len(stack);
	if (median % 2 == 0)
		median /= 2;
	else
		median = (median + 1) / 2;
	while (stack)
	{
		if (i < median)
		{
			stack->above_median = 1;
			stack->index = i;
		}
		else
		{
			stack->above_median = 0;
			stack->index = i;
		}
		i++;
		stack = stack->next;
	}
}

t_stack	*get_node_min_move(t_stack *stack)
{
	int		min_mov;
	t_stack	*node;

	if (!stack)
		return (NULL);
	min_mov = INT_MAX;
	while (stack)
	{
		if (stack->min_mov < min_mov)
		{
			min_mov = stack->min_mov;
			node = stack;
		}
		stack = stack->next;
	}
	return (node);
}

void	min_move_on_top(t_stack **stack, t_stack *tmp, int bol)
{
	while (*stack != tmp)
	{
		if (tmp->above_median)
		{
			if (bol)
				ra(stack);
			else
				rb(stack);
		}
		else
		{
			if (bol)
				rra(stack);
			else
				rrb(stack);
		}
	}
}

void	move_min_on_top(t_stack **stack, int five)
{
	t_stack	*min_node;

	min_node = get_min_node(*stack);
	while (*stack != min_node)
	{
		if (five)
		{
			if (!min_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else
		{
			if (!min_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
	}
}
