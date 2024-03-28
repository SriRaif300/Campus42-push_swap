/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/27 17:32:51 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack **a)
{
	int	max;

	max = max_node(*a)->num;
	if ((*a)->num == max)
		ra(a, 0);
	else if ((*a)->next->num == max)
		rra(a, 0);
	if ((*a)->next->num < (*a)->num)
		sa(a, 0);
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
