/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgaratej <cgaratej@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 10:10:23 by cgaratej          #+#    #+#             */
/*   Updated: 2024/04/03 12:39:27 by cgaratej         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

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
void	check_u_long_max(char **argv);

/* utils */
long	ft_atol(char *str);
int		is_sort_list(t_stack *stack);
t_stack	*ft_last_node(t_stack *stack);
void	fill_stack(t_stack **a, char **argv);
int		stack_len(t_stack *stack);
void	free_stack(t_stack **stack);
t_stack	*get_max_node(t_stack *stack);
t_stack	*get_min_node(t_stack *stack);
void	set_post(t_stack *stack);
void	set_min_mov(t_stack *a, t_stack *b);
t_stack	*get_node_min_move(t_stack *stack);
void	min_move_on_top(t_stack **stack, t_stack *tmp, int bol);
void	move_min_on_top(t_stack **stack, int five);
void	sort_three(t_stack **a);
void	sort(t_stack **a, t_stack **b, int five);

/* Commands */
void	sa(t_stack **a);
void	sb(t_stack **b);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **a, t_stack **b);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **a);
void	rb(t_stack **b);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **a);
void	rrb(t_stack **b);
void	rrr(t_stack **a, t_stack **b);

#endif