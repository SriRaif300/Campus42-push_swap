/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:38:59 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/20 16:03:56 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*frist_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_last_node(*stack);
	frist_node = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next = frist_node;
	frist_node->next = NULL;
	frist_node->prev = last_node;
}

void	ra(t_stack **a, int check)
{
	rotate(a);
	if (!check)
		write(1, "ra\n", 3);
}

void	rb(t_stack **b, int check)
{
	rotate(b);
	if (!check)
		write(1, "rb\n", 3);
}

void	rr(t_stack **a, t_stack **b, int check)
{
	rotate(a);
	rotate(b);
	if (!check)
		write(1, "rr\n", 3);
}
