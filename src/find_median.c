/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_median.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 12:09:11 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/25 18:02:52 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*get_array_nums(t_stack *stack)
{
	int	len;
	int	*nums;
	int	i;

	len = stack_len(stack);
	nums = (int *)malloc((len + 1) * sizeof(int));
	if (!nums)
		return (exit(1), NULL);
	i = 0;
	while (i < len)
	{
		nums[i] = stack->num;
		if (!nums)
			return (free(nums), NULL);
		i++;
		stack = stack->next;
	}
	nums[i] = '\0';
	return (nums);
}

static int	find_min(int *nums, int len)
{
	int	i;
	int	min;

	i = 0;
	min = nums[i];
	while (i < len)
	{
		if (nums[i] < min)
			min = nums[i];
		i++;
	}
	return (min);
}

int	find_median(int *array, int median, int len)
{
	int	i;
	int	min;
	int	tmp;

	if (median % 2 == 0)
		median /= 2;
	else
		median = (median + 1) / 2;
	while (median--)
	{
		min = find_min(array, len);
		i = 0;
		while (i < len)
		{
			if (array[i] == min)
			{
				tmp = array[i];
				array[i] = INT_MAX;
				break ;
			}
			i++;
		}
	}
	return (tmp);
}
