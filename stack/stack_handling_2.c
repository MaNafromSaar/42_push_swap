/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:58:33 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:58:33 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	stack_size(t_stack_node *stack)
{
	int	size;

	size = 0;
	if (!stack)
		return (0);
	while (stack != NULL)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	t_stack_node	*temp;

	temp = stack;
	while (temp && temp->next)
		temp = temp->next;
	return (temp);
}

bool	stack_is_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (false);
		stack = stack->next;
	}
	return (true);
}

t_stack_node	*find_max(t_stack_node *stack)
{
	t_stack_node	*max;

	if (!stack)
		return (NULL);
	max = stack;
	while (stack)
	{
		if (stack->data > max->data)
			max = stack;
		stack = stack->next;
	}
	return (max);
}

t_stack_node	*find_min(t_stack_node *stack)
{
	t_stack_node	*min;

	if (!stack)
		return (NULL);
	min = stack;
	while (stack)
	{
		if (stack->data < min->data)
			min = stack;
		stack = stack->next;
	}
	return (min);
}
