/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:50:25 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 20:20:51 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	move_range_to_b(int min, int max, t_list *stack_a, t_list *stack_b)
{
	const int	cnt = max - min;
	int			move_cnt;

	move_cnt = 0;
	while (move_cnt < cnt)
	{
		if (min < stack_a->head->next->value
			&& stack_a->head->next->value <= max)
		{
			cmd_pb(stack_a, stack_b);
			++move_cnt;
		}
		else
			cmd_ra(stack_a);
	}
}

void	stack_a_b_setting(t_list *stack_a, t_list *stack_b)
{
	const int	min_val = 2;
	const int	except = 4;
	const int	max_val = stack_a->size;
	int			min_pivot;
	int			max_pivot;

	min_pivot = (max_val - except) / 3 + except - 1;
	max_pivot = (max_val - except) / 3 * 2 + except - 1;
	move_range_to_b(min_val, min_pivot, stack_a, stack_b);
	move_range_to_b(min_pivot, max_pivot, stack_a, stack_b);
	move_range_to_b(max_pivot, max_val - 1 - 1, stack_a, stack_b);
	find_max_idx(stack_a, stack_b);
	stack_a_in_three_node(stack_a);
	cmd_pa(stack_b, stack_a);
}

void	stack_a_round(t_list *stack_a, int *temp_total)
{
	t_node	*a_temp;
	int		idx;

	idx = 0;
	a_temp = stack_a->head->next;
	temp_total[1] = 0;
	temp_total[2] = 0;
	if (a_temp->value > temp_total[0] && a_temp->prev->value < temp_total[0])
		return ;
	while (!(a_temp->value < temp_total[0]
			&& a_temp->next->value > temp_total[0]))
	{
		idx++;
		a_temp = a_temp->next;
	}
	stack_a_round2(stack_a, temp_total, a_temp, idx);
}

void	stack_a_round2(t_list *stack_a, int *temp_total,
		t_node *a_temp, int idx)
{
	while (a_temp != stack_a->head->next->prev)
	{
		if (idx < stack_a->size / 2)
		{
			a_temp = a_temp->prev;
			temp_total[1]++;
		}
		else
		{
			a_temp = a_temp->next;
			temp_total[2]++;
		}
	}
}

void	stack_b_round(t_list *stack_b, t_node *temp, int *temp_total, int idx)
{
	temp_total[3] = 0;
	temp_total[4] = 0;
	while (temp != stack_b->head->next)
	{
		if (idx < stack_b->size / 2)
		{
			temp = temp->prev;
			temp_total[3]++;
		}
		else
		{
			temp = temp->next;
			temp_total[4]++;
		}
	}
}
