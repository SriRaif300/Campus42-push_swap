/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 11:32:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/21 11:47:48 by cgaratej         ###   ########.fr       */
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
