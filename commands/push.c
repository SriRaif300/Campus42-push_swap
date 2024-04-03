/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:36:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 11:31:59 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	push(t_stack **origin, t_stack **dest)
{
	t_stack	*frist_node;

	frist_node = *origin;
	*origin = (*origin)->next;
	if (*origin)
		(*origin)->prev = NULL;
	if (!*dest)
	{
		*dest = frist_node;
		(*dest)->next = NULL;
	}
	else
	{
		(*dest)->prev = frist_node;
		frist_node->next = *dest;
		*dest = frist_node;
	}
}

void	pa(t_stack **a, t_stack **b)
{
	if (!b)
		return ;
	push(b, a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b)
{
	if (!a)
		return ;
	push(a, b);
	write(1, "pb\n", 3);
}
