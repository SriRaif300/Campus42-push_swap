/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/25 15:25:48 by cgaratej         ###   ########.fr       */
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
	int	*array;
	int	len;

	i = 0;
	len = stack_len(stack);
	array = get_array_nums(stack);
	median = find_median(array, 0, len);
	free(array);
	while (stack)
	{
		if (i < median)
		{
			stack->above_median = 1;
			stack->pos = i;
		}
		else
		{
			stack->above_median = 0;
			stack->pos = i;
		}
		i++;
		stack = stack->next;
	}
}
