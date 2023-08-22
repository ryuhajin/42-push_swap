/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   greedy.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/22 21:14:49 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void A_to_B (t_list * stack_A, t_list * stack_B)
{
	int min_pivot;
	int max_pivot;
	int input_max;

	input_max = stack_A->size; // 30
	min_pivot = (stack_A->size / 3); // 10
	max_pivot = min_pivot * 2; // 20
	min_to_stack_B(min_pivot, stack_A, stack_B);
	// printf("min end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	middle_to_stack_B(min_pivot, stack_A, stack_B);
	// printf("middle end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	max_to_stack_B(input_max, stack_A, stack_B);
	// printf("max end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	stack_A_in_three_node (stack_A);
	print_list(stack_A);
	print_list(stack_B);
}

void min_to_stack_B (int min_pivot, t_list * stack_A, t_list * stack_B)
{
	int max_pivot;
	
	max_pivot = min_pivot * 2;
	while (stack_A->size > max_pivot + 3)
	{
		if (stack_A->head->next->value < min_pivot &&
		stack_A->head->next->value > 2)
		{	
			cmd_pb(stack_A, stack_B);
		}
		else
			cmd_ra(stack_A);
	}	
}

void middle_to_stack_B (int min_pivot, t_list * stack_A, t_list * stack_B)
{
	int max_pivot;

	max_pivot = min_pivot * 2;
	while (stack_A->size > min_pivot + 3)
	{
		if (stack_A->head->next->value < max_pivot
		&& stack_A->head->next->value > 2)
			cmd_pb(stack_A, stack_B);
		else
			cmd_ra(stack_A);
	}
}

void max_to_stack_B (int input_max, t_list * stack_A, t_list * stack_B)
{
	while (stack_A->size > 3)
	{
		if (stack_A->head->next->value < input_max && stack_A->head->next->value > 2)
			cmd_pb(stack_A, stack_B);
		else
			cmd_ra(stack_A);
	}	
}

void stack_A_in_three_node (t_list * stack_A)
{
	if (stack_A->size < 3)
		return;
	if (stack_A->head->next->value == 0)
	{
		cmd_sa(stack_A);
		cmd_ra(stack_A);
	}
	else if (stack_A->head->next->value == 1)
	{
		if (stack_A->head->next->next->value == 2)
			cmd_rra(stack_A);
		else
			cmd_sa(stack_A);
	}
	else
	{
		if (stack_A->head->next->next->value == 0)
			cmd_ra(stack_A);
		else
			cmd_sa(stack_A);
			cmd_rra(stack_A);
	}
}
