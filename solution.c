/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:41:48 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/push_swap.h"

void stack_A_in_two_node (t_list * stack_A)
{
	cmd_sa(stack_A);
}

void stack_A_in_three_node (t_list * stack_A)
{
	if (stack_A->size < 3 || stack_A->size > 3)
		return;
	if (stack_A->head->next->value == 0)
	{
		if (stack_A->head->next->next->value == 2)
		{
			cmd_sa(stack_A);
			cmd_ra(stack_A);
		}
	}
	else if (stack_A->head->next->value == 1)
	{
		if (stack_A->head->next->next->value == 2)
			cmd_rra(stack_A);
		else
			cmd_sa(stack_A);
	}
	else if (stack_A->head->next->value == 2)
	{
		if (stack_A->head->next->next->value == 1)
		{	
			cmd_sa(stack_A);
			cmd_rra(stack_A);
		}
		else
			cmd_ra(stack_A);
	}
}

void stack_A_in_four_node (t_list * stack_A, t_list * stack_B)
{
	find_max_idx(stack_A, stack_B);
	stack_A_in_three_node(stack_A);
	cmd_pa(stack_B, stack_A);
	cmd_ra(stack_A);
}

int stack_A_size_too_small (t_list * stack_A, t_list * stack_B)
{
	if (stack_A->size > 4)
		return 1;
	else if (stack_A->size == 2)
		stack_A_in_two_node(stack_A);
	else if (stack_A->size == 3)
		stack_A_in_three_node(stack_A);
	else
		stack_A_in_four_node(stack_A, stack_B);
	fclear_list(stack_A);
	fclear_list(stack_B);
	return 0;
}
