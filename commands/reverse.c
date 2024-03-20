/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 16:08:33 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/20 16:23:19 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	reverse(t_stack **stack)
{
	t_stack	*frist_node;
	t_stack	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = ft_last_node(*stack);
	frist_node = *stack;
	*stack = last_node;
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = frist_node;
	frist_node->prev = frist_node;
}

void	rra(t_stack **a, int check)
{
	reverse(a);
	if (!check)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **b, int check)
{
	reverse(b);
	if (!check)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **a, t_stack **b, int check)
{
	reverse(a);
	reverse(b);
	if (!check)
		write(1, "rrr\n", 4);
}
