/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:10:23 by cgaratej          #+#    #+#             */
/*   Updated: 2024/03/27 17:33:37 by cgaratej         ###   ########.fr       */
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
	int				index;
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

/* utils */
long	ft_atol(char *str);
int		is_sort_list(t_stack *stack);
t_stack	*ft_last_node(t_stack *stack);
void	fill_stack(t_stack **a, char **argv);
int		stack_len(t_stack *stack);
t_stack	*max_node(t_stack *stack);
t_stack	*min_node(t_stack *stack);
void	sort_three(t_stack **a);
void	set_post(t_stack *stack);
int		find_median(int *array, int median, int len);
int		*get_array_nums(t_stack *stack);
void	sort(t_stack **a, t_stack **b, int len);
void	set_min_mov(t_stack *a, t_stack *b);
t_stack	*get_node_min_move(t_stack *stack);

/* Commands */
void	sa(t_stack **a, int check);
void	sb(t_stack **b, int check);
void	ss(t_stack **a, t_stack **b, int check);
void	pa(t_stack **a, t_stack **b, int check);
void	pb(t_stack **a, t_stack **b, int check);
void	ra(t_stack **a, int check);
void	rb(t_stack **b, int check);
void	rr(t_stack **a, t_stack **b, int check);
void	rra(t_stack **a, int check);
void	rrb(t_stack **b, int check);
void	rrr(t_stack **a, t_stack **b, int check);

#endif