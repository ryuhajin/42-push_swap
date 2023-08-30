/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:44 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 20:04:35 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	r_compare(int *temp_total, int idx)
{
	if (temp_total[idx] == temp_total[idx + 2])
	{
		temp_total[idx + 4] = temp_total[idx];
		temp_total[idx] = 0;
		temp_total[idx + 2] = 0;
	}
	else if (temp_total[idx] > temp_total[idx + 2])
	{
		temp_total[idx + 4] = temp_total[idx + 2];
		temp_total[idx] = temp_total[idx] - temp_total[idx + 2];
		temp_total[idx + 2] = 0;
	}
	else
	{
		temp_total[idx + 4] = temp_total[idx];
		temp_total[idx + 2] = temp_total[idx + 2] - temp_total[idx];
		temp_total[idx] = 0;
	}
}

void	cmd_count(int *temp_total)
{
	int	i;
	int	cmd_cnt;

	i = 1;
	cmd_cnt = 0;
	while (i < 7)
	{
		cmd_cnt += temp_total[i];
		i++;
	}
	temp_total[7] = cmd_cnt;
}

void	copy_cmd(int *temp_total, int *min_cmd)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		min_cmd[i] = temp_total[i];
		i++;
	}
}

void	find_max_idx(t_list *stack_a, t_list *stack_b)
{
	while (stack_a->head->next->value != stack_a->idx_size - 1)
		cmd_ra(stack_a);
	cmd_pb(stack_a, stack_b);
}

void	cnt_optimization(int *temp_total, int *min_cmd)
{
	r_compare(temp_total, 1);
	r_compare(temp_total, 2);
	cmd_count(temp_total);
	if (temp_total[7] < min_cmd[7])
		copy_cmd(temp_total, min_cmd);
}
