/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:40 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 21:53:58 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	cmd_reset(int *arr)
{
	int	i;

	i = 0;
	while (i++ < 8)
	{
		arr[i] = INT_MAX;
	}
}

void	one_round_count(t_list *stack_a, t_list *stack_b, int *min_cmd)
{
	t_node	*temp;
	int		idx;
	int		temp_total[8];

	temp = stack_b->head->next;
	idx = 0;
	while (idx < stack_b->size)
	{
		temp_total[0] = temp->value;
		stack_b_round(stack_b, temp, temp_total, idx);
		stack_a_round(stack_a, temp_total);
		cnt_optimization(temp_total, min_cmd);
		temp = (search_node(stack_b, temp_total[0]))->next;
		idx++;
	}
}

void	cmd_call(t_list *stack_a, t_list *stack_b, int *min_cmd)
{
	int	i;

	i = 0;
	while (i++ < min_cmd[5])
		cmd_rr(stack_a, stack_b);
	i = 0;
	while (i++ < min_cmd[1])
		cmd_ra(stack_a);
	i = 0;
	while (i++ < min_cmd[3])
		cmd_rb(stack_b);
	i = 0;
	while (i++ < min_cmd[6])
		cmd_rrr(stack_a, stack_b);
	i = 0;
	while (i++ < min_cmd[2])
		cmd_rra(stack_a);
	i = 0;
	while (i++ < min_cmd[4])
		cmd_rrb(stack_b);
}

void	last_stack_a_sort(t_list *stack_a)
{
	t_node	*temp;
	t_node	*head_node;
	int		idx;

	temp = stack_a->head->next;
	head_node = search_node(stack_a, 0);
	idx = 0;
	while (temp != head_node)
	{
		idx++;
		temp = temp->next;
	}
	while (stack_a->head->next->value != 0)
	{
		if (idx <= stack_a->size / 2)
			cmd_ra(stack_a);
		else
			cmd_rra(stack_a);
	}
}

void	solution_commander(t_list *stack_a, t_list *stack_b)
{
	int	min_cmd[8];

	stack_a_b_setting(stack_a, stack_b);
	while (stack_b->size != 0)
	{
		cmd_reset(min_cmd);
		one_round_count(stack_a, stack_b, min_cmd);
		cmd_call(stack_a, stack_b, min_cmd);
		cmd_pa(stack_b, stack_a);
	}
	last_stack_a_sort(stack_a);
	fclear_list(stack_b);
	fclear_list(stack_a);
}
