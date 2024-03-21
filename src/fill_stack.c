/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 14:54:57 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/21 11:57:40 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

static void	append_node(t_stack **a, int num)
{
	t_stack	*new_node;
	t_stack	*last_node;

	if (!a)
		return ;
	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return ;
	new_node->num = num;
	new_node->next = NULL;
	if (!*a)
	{
		*a = new_node;
		new_node->prev = NULL;
	}
	else
	{
		last_node = ft_last_node(*a);
		last_node->next = new_node;
		new_node->prev = last_node;
	}
}

void	fill_stack(t_stack **a, char **argv)
{
	int	num;
	int	i;

	i = 1;
	while (argv[i])
	{
		num = (int)ft_atol(argv[i]);
		append_node(a, num);
		i++;
	}
}

void	free_stack(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*next;

	if (*stack && stack)
	{
		tmp = stack;
		while (tmp)
		{
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
		*stack = NULL;
	}
}
