/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handling_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:58:21 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:58:21 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

long	atoi_long(const char *s)
{
	long	res;
	int		sign;

	res = 0;
	sign = 1;
	if (!s)
		error_handling(NULL);
	while ((*s >= 9 && *s <= 13) || *s == 32)
		s++;
	if (*s == '-' || *s == '+')
	{
		if (!ft_isdigit(*(s + 1)))
			error_handling(NULL);
		if (*s == '-')
			sign = -1;
		s++;
	}
	while (ft_isdigit(*s))
	{
		res = res * 10 + *s - '0';
		s++;
	}
	if (!ft_isdigit(*s) && *s != '\0' && (*s != 32 || !(*s >= 9 && *s <= 13)))
		error_handling(NULL);
	return (res * sign);
}

static void	append_node(t_stack_node **stack, int data)
{
	t_stack_node	*new_node;
	t_stack_node	*last;

	new_node = (t_stack_node *)malloc(sizeof(t_stack_node));
	if (!stack || !new_node)
		return ;
	new_node->data = data;
	new_node->next = NULL;
	new_node->above_median = false;
	new_node->cheapest = false;
	new_node->prev = NULL;
	if (!*stack)
		*stack = new_node;
	else
	{
		last = find_last(*stack);
		last->next = new_node;
		new_node->prev = last;
	}
}

void	initialize_stack(t_stack_node **stack, char **args)
{
	long	n;
	int		i;

	i = 0;
	while (args[i])
	{
		if (input_error(args[i]))
			error_handling(stack);
		n = atoi_long(args[i]);
		if (n > INT_MAX || n < INT_MIN)
			error_handling(stack);
		if (duplicate_error(*stack, (int)n))
			error_handling(stack);
		append_node(stack, n);
		i++;
	}
}

void	prep_push(t_stack_node **stack, t_stack_node *top_node,
						char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a' && top_node->above_median)
		{
			ra(stack);
			write(1, "ra\n", 3);
		}
		else if (stack_name == 'b' && top_node->above_median)
		{
			rb(stack);
			write(1, "rb\n", 3);
		}
		else if (stack_name == 'a' && !(top_node->above_median))
		{
			rra(stack);
			write(1, "rra\n", 4);
		}
		else if (stack_name == 'b' && !(top_node->above_median))
		{
			rrb(stack);
			write(1, "rrb\n", 4);
		}
	}
}
