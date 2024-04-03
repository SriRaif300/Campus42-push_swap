/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:30:09 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 12:40:23 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	check_u_long_max(argv);
	if (syntax_error(argv) || int_error(argv) || dup_error(argv))
		print_error();
	fill_stack(&a, argv);
	if (!is_sort_list(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else if (stack_len(a) >= 5)
			sort(&a, &b, 1);
		else
			sort(&a, &b, 0);
	}
	free_stack(&a);
	return (0);
}
