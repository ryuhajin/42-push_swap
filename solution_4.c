/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_4.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:31:40 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 15:46:23 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "./headers/push_swap.h"

void cmd_reset (int * arr)
{
	int i;

	i = 0;

	while (i++ < 8)
	{
		arr[i] = INT_MAX;
	}
}

void one_round_count (t_list * stack_A, t_list * stack_B, int * min_cmd)
{
	t_node * temp;
	
	int temp_total[8]; // temp 값
	// index[0] ra[1] rra[2] rb[3] rrb[4] rr[5] rrr[6] cmd_cnt[7]
	int idx;
	

	temp = stack_B->head->next;
	idx = 0;
	while (idx < stack_B->size)
	{
		temp_total[0] = temp->value;
		stack_B_round(stack_B, temp, temp_total, idx);
		stack_A_round(stack_A, temp_total);
		cnt_optimization(temp_total, min_cmd);
		temp = (search_node(stack_B, temp_total[0]))->next;
		idx++;
	}
}

void cmd_call (t_list * stack_A, t_list * stack_B, int * min_cmd)
{
	int i;
	// index[0] ra[1] rra[2] rb[3] rrb[4] rr[5] rrr[6] cmd_cnt[7]
	i = 0;
	while (i++ < min_cmd[5])
		cmd_rr(stack_A, stack_B);
	i = 0;
	while (i++ < min_cmd[1])
		cmd_ra(stack_A);
	i = 0;
	while (i++ < min_cmd[3])
		cmd_rb(stack_B);
	i = 0;
	while (i++ < min_cmd[6])
		cmd_rrr(stack_A, stack_B);
	i = 0;
	while (i++ < min_cmd[2])
		cmd_rra(stack_A);
	i = 0;
	while (i++ < min_cmd[4])
		cmd_rrb(stack_B);
}

void last_stack_A_sort (t_list * stack_A)
{
	t_node * temp;
	t_node * head_node;
	int idx;

	temp = stack_A->head->next;
	head_node = search_node(stack_A, 0);
	idx = 0;
	while (temp != head_node)
	{
		idx++;
		temp = temp->next;
	}

	while (stack_A->head->next->value != 0)
	{
		if (idx <= stack_A->size/2)
			cmd_ra(stack_A);
		else
			cmd_rra(stack_A);
	}
}

void solution_commander (t_list * stack_A, t_list * stack_B) // b가 비워질 때 까지 도는 함수
{
	int min_cmd[8];

	stack_A_B_setting(stack_A, stack_B);
	while (stack_B->size != 0)
	{
		cmd_reset(min_cmd);
		one_round_count(stack_A, stack_B, min_cmd);
		cmd_call(stack_A, stack_B, min_cmd);
		cmd_pa(stack_B, stack_A);
		// print_list(stack_A);
		// print_list(stack_B);
	}
	last_stack_A_sort(stack_A);
	fclear_list(stack_B);
	fclear_list(stack_A);
}
