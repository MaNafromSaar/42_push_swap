/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnaumann <mnaumann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 11:58:57 by mnaumann          #+#    #+#             */
/*   Updated: 2024/07/02 11:58:57 by mnaumann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	select_case(t_stack_node **a, t_stack_node **b)
{
	int	size;

	size = stack_size(*a);
	if (size > 5)
		case_x(a, b);
	else if (size == 5)
		case_5(a, b);
	else if (size == 4)
		case_4(a, b);
	else if (size == 3)
		case_3(a);
	else if (size == 2)
		sa(a);
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**args;
	int				i;

	a = NULL;
	b = NULL;
	i = 1;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		exit(1);
	if (argc == 2)
		args = split(argv[1], ' ');
	else
		args = &argv[i++];
	initialize_stack(&a, args);
	if (stack_is_sorted(a))
		return (0);
	select_case(&a, &b);
	free_stack(&a);
	return (0);
}

//printing state of stack
	// current = a;
	// while (current)
	// {
	// 	printf("%d ", current->data);
	// 	current = current->next;
	// }
	// printf("\n");
	// free_stack(&a);
//checking read-in
// 	char **temp_args = args;
// printf("args: ");
// while (*temp_args != NULL) {
//     printf("%s ", *temp_args);
//     temp_args++;
//}
//printf("\n");