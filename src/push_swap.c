/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:30:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/25 17:56:02 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_stack(t_stack *stack, char c)
{
	printf("Contenido del stack %c:\n", c);
	while (stack != NULL)
	{
		printf("%d\n", stack->num); 
		stack = stack->next;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	if (syntax_error(argv) || int_error(argv) || dup_error(argv))
		print_error();
	fill_stack(&a, argv);
	if (!is_sort_list(a))
	{
		if (stack_len(a) == 2)
			sa(&a, 0);
		if (stack_len(a) == 3)
			sort_three(&a);
		else
		{
			print_stack(a, 'a');
			sort(&a, &b);
			print_stack(a, 'a');
			print_stack(b, 'b');
		}
	}
	/*print_stack(a, 'a');
	print_stack(b, 'b');
	rrr(&a ,&b, 0);
	print_stack(a, 'a');
	print_stack(b, 'b');*/
	return (0);
}
