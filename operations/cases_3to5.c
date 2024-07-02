/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cases_3to5.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 20:49:37 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/01 20:49:37 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_3(t_stack_node **a)
{
	t_stack_node	*max;

	indexing(*a);
	max = find_max(*a);
	if (stack_is_sorted(*a))
		return ;
	if ((*a)->data == max->data)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	else if ((*a)->next->data == max->data)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if ((*a)->data > (*a)->next->data)
		sa(a);
}

void	case_4(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	if (stack_is_sorted(*a))
		return ;
	indexing(*a);
	min = find_min(*a);
	while (min->above_median && *a != min)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	while (!(min->above_median) && *a != min)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if (stack_is_sorted(*a))
		return ;
	pb(a, b);
	case_3(a);
	pa(b, a);
	indexing(*a);
}

void	case_5(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*min;

	indexing(*a);
	min = find_min(*a);
	while (min->above_median && *a != min)
	{
		ra(a);
		write(1, "ra\n", 3);
	}
	while (!(min->above_median) && *a != min)
	{
		rra(a);
		write(1, "rra\n", 4);
	}
	if (stack_is_sorted(*a))
		return ;
	pb(a, b);
	case_4(a, b);
	pa(b, a);
	indexing(*a);
}
