/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   case_x.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:57:12 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:57:12 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_stacks(t_stack_node **a, t_stack_node **b,
	t_stack_node *cheapest)
{
	while ((*b != cheapest->target && *a != cheapest) && (cheapest->above_median
			&& cheapest->target->above_median))
	{
		rr(a, b);
		write(1, "rr\n", 3);
	}
	while ((*b != cheapest->target && *a != cheapest)
		&& (!(cheapest->above_median) && !(cheapest->target->above_median)))
	{
		rrr(a, b);
		write(1, "rrr\n", 4);
	}
	indexing(*a);
	indexing(*b);
}

static void	move_a_to_b(t_stack_node **b, t_stack_node **a)
{
	t_stack_node	*cheapest;

	cheapest = get_cheapest(*a);
	if (cheapest == NULL || cheapest->target == NULL)
		return ;
	if (cheapest->above_median && cheapest->target->above_median)
		rotate_stacks(a, b, cheapest);
	else if (!cheapest->above_median && !cheapest->target->above_median)
		rotate_stacks(a, b, cheapest);
	else if (cheapest->above_median && !cheapest->target->above_median)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if (!cheapest->above_median && cheapest->target->above_median
		&& stack_size(*b) > 1)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	prep_push(a, cheapest, 'a');
	prep_push(b, cheapest->target, 'b');
	pb(a, b);
}

static void	move_b_to_a(t_stack_node **a, t_stack_node **b)
{
	prep_push(a, (*b)->target, 'a');
	pa(b, a);
}

static void	min_on_top(t_stack_node **stack)
{
	t_stack_node	*min;

	min = find_min(*stack);
	while (*stack != min)
	{
		if (min->above_median)
		{
			ra(stack);
			write(1, "ra\n", 3);
		}
		else
		{
			rra(stack);
			write(1, "rra\n", 4);
		}
	}
}

void	case_x(t_stack_node **a, t_stack_node **b)
{
	if (stack_is_sorted(*a))
		return ;
	pb(a, b);
	if (stack_size(*a) > 5 && !stack_is_sorted(*a))
		pb(a, b);
	while (stack_size(*a) > 5)
	{
		prep_cheapest(*a, *b);
		move_a_to_b(b, a);
	}
	if (stack_size(*a) == 5)
		case_5(a, b);
	while (*b)
	{
		b_to_a(*a, *b);
		move_b_to_a(a, b);
	}
	indexing(*a);
	min_on_top(a);
}
