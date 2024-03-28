/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:43:45 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/27 13:24:36 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	set_movements(t_stack *stack)
{
	int	len;

	len = stack_len(stack);
	while (stack)
	{
		if (stack->above_median)
			stack->min_mov = stack->index;
		else
			stack->min_mov = len - stack->index;
		stack = stack->next;
	}
}

static void	sum_target_mov(t_stack *stack)
{
	while (stack)
	{
		if (stack->above_median == stack->target->above_median
			&& stack->min_mov < stack->target->min_mov)
			stack->min_mov = stack->target->min_mov;
		else if (stack->above_median != stack->target->above_median)
			stack->min_mov = stack->min_mov + stack->target->min_mov;
		stack = stack->next;
	}
}

void	set_min_mov(t_stack *a, t_stack *b)
{
	set_movements(a);
	set_movements(b);
	sum_target_mov(a);
}
