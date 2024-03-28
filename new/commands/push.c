/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:36:28 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/25 16:41:29 by cgaratej         ###   ########.fr       */
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

void	pa(t_stack **a, t_stack **b, int check)
{
	if (!b)
		return ;
	push(b, a);
	if (!check)
		write(1, "pa\n", 3);
}

void	pb(t_stack **a, t_stack **b, int check)
{
	if (!a)
		return ;
	push(a, b);
	if (!check)
		write(1, "pb\n", 3);
}
