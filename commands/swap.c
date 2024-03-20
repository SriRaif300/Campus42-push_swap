/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:26:26 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/14 17:24:46 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack **stack)
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

void	sa(t_stack **a, int check)
{
	if (!*a)
		return ;
	swap(a);
	if (!check)
		write(1, "sa\n", 3);
}

void	sb(t_stack **b, int check)
{
	if (!*b)
		return ;
	swap(b);
	if (!check)
		write(1, "sb\n", 3);
}

void	ss(t_stack **a, t_stack **b, int check)
{
	if (!*a || !*b)
		return ;
	swap(a);
	swap(b);
	if (!check)
		write(1, "ss\n", 3);
}
