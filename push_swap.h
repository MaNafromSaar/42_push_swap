/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 10:01:22 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 10:01:22 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
//# include <libft.h>

typedef struct s_stack_node
{
	int					data;
	int					index;
	int					cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

// operations
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **b, t_stack_node **a);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);

// sorting
void			case_3(t_stack_node **a);
void			case_4(t_stack_node **a, t_stack_node **b);
void			case_5(t_stack_node **a, t_stack_node **b);
void			case_x(t_stack_node **a, t_stack_node **b);

//struct specific
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*get_cheapest(t_stack_node *a);
t_stack_node	*cheapest_cost(t_stack_node *a, t_stack_node *b);

//utils
int				stack_size(t_stack_node *stack);
bool			stack_is_sorted(t_stack_node *stack);
void			set_cheapest(t_stack_node *a);
void			prep_cheapest(t_stack_node *a, t_stack_node *b);
void			indexing(t_stack_node *stack);
void			prep_push(t_stack_node **stack, t_stack_node *node,
					char stack_name);
void			initialize_stack(t_stack_node **stack, char **argv);
char			**split(const char *s, char c);
long			atoi_long(const char *s);
int				ft_isdigit(int c);
void			b_to_a(t_stack_node *a, t_stack_node *b);

// error handling
int				input_error(char *str);
int				duplicate_error(t_stack_node *stack, int data);
void			free_stack(t_stack_node **stack);
void			error_handling(t_stack_node **a);

#endif