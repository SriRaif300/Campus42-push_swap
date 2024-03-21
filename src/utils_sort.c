/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/21 16:27:06 by cgaratej         ###   ########.fr       */
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
	int	mediana;
	int	i;

	i = 0;
	mediana = stack_len(stack);
	if (mediana % 2 == 0)
		mediana /= 2;
	else
		mediana = (mediana + 1) / 2;
	while (stack)
	{
		if (i < mediana)
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
