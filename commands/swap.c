/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:26:26 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 11:32:54 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (*stack || (*stack)->next)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
		if (tmp->next)
			tmp->next->prev = tmp;
		tmp->prev = *stack;
		(*stack)->prev = NULL;
	}
}

void	sa(t_stack **a)
{
	if (!*a)
		return ;
	swap(a);
	write(1, "sa\n", 3);
}

void	sb(t_stack **b)
{
	if (!*b)
		return ;
	swap(b);
	write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b)
{
	if (!*a || !*b)
		return ;
	swap(a);
	swap(b);
	write(1, "ss\n", 3);
}
