/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:04:53 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	stack_a_in_two_node(t_list *stack_a)
{
	cmd_sa(stack_a);
}

void	stack_a_in_three_node(t_list *stack_a)
{
	if (stack_a->head->next->value == 0
		&& stack_a->head->next->next->value == 2)
	{
		cmd_sa(stack_a);
		cmd_ra(stack_a);
	}
	else if (stack_a->head->next->value == 1)
	{
		if (stack_a->head->next->next->value == 2)
			cmd_rra(stack_a);
		else
			cmd_sa(stack_a);
	}
	else if (stack_a->head->next->value == 2)
	{
		if (stack_a->head->next->next->value == 1)
		{
			cmd_sa(stack_a);
			cmd_rra(stack_a);
		}
		else
			cmd_ra(stack_a);
	}
}

void	stack_a_in_four_or_five(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size == 4)
	{
		find_max_idx(stack_a, stack_b);
		stack_a_in_three_node(stack_a);
		cmd_pa(stack_b, stack_a);
		cmd_ra(stack_a);
	}
	else if (stack_a->size == 5)
	{
		move_range_to_b(2, 4, stack_a, stack_b);
		if (stack_b->head->next->value < stack_b->head->next->prev->value)
			cmd_sb(stack_b);
		stack_a_in_three_node(stack_a);
		cmd_pa(stack_b, stack_a);
		cmd_pa(stack_b, stack_a);
		cmd_ra(stack_a);
		cmd_ra(stack_a);
	}
}

int	stack_a_size_too_small(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size > 5)
		return (success);
	else if (stack_a->size == 2)
		stack_a_in_two_node(stack_a);
	else if (stack_a->size == 3)
		stack_a_in_three_node(stack_a);
	else if (stack_a->size == 4 || stack_a->size == 5)
		stack_a_in_four_or_five(stack_a, stack_b);
	fclear_2_lists(stack_a, stack_b);
	return (failed);
}
