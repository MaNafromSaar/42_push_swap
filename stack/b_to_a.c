/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:58:11 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:58:11 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	set_target_b(t_stack_node *b, t_stack_node *a)
{
	t_stack_node	*tmp_a;
	t_stack_node	*target_a;
	long			match_index;

	while (b)
	{
		tmp_a = a;
		match_index = LONG_MAX;
		while (tmp_a)
		{
			if (tmp_a->data > b->data && tmp_a->data < match_index)
			{
				match_index = tmp_a->data;
				target_a = tmp_a;
			}
			tmp_a = tmp_a->next;
		}
		if (match_index == LONG_MAX)
			b->target = find_min(a);
		else
			b->target = target_a;
		b = b->next;
	}
}

void	b_to_a(t_stack_node *a, t_stack_node *b)
{
	indexing(a);
	indexing(b);
	set_target_b(b, a);
}

t_stack_node	*get_cheapest(t_stack_node *a)
{
	if (!a)
		return (NULL);
	while (a)
	{
		if (a->cheapest)
			return (a);
		a = a->next;
	}
	return (NULL);
}
