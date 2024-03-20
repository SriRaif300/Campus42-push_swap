/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:10:23 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/14 15:36:08 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				pos;
	int				above_median;
	int				min_mov;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

/* funcions errors */
int		int_error(char **argv);
int		syntax_error(char **argv);
int		dup_error(char **argv);
void	print_error(void);

long	ft_atol(char *str);
int		is_sort_list(t_stack *lst);
t_stack	*ft_last_node(t_stack *lst);
void	fill_stack(t_stack **a, char **argv);

#endif