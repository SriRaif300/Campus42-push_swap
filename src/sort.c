/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 11:30:58 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/25 18:06:31 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	min_target(t_stack *a, t_stack *b)
{
	
}

void	sort(t_stack **a, t_stack **b)
{
	int	len;
	int	i;

	len = stack_len(*a);
	i = 0;
	while (i++ < 2 && len-- > 3 && !is_sort_list(*a))
		pb(a, b, 0);
	while (len-- > 3 && !is_sorted(*a))
	{
		set_pos(*a);
		set_pos(*b);
		min_target(*a, *b);
	}
}
