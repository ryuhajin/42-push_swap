/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 18:00:29 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void find_max_idx (t_list * stack_A, t_list * stack_B)
{
	while (stack_A->head->next->value != stack_A->idx_size -1)
		cmd_ra(stack_A);
	cmd_pb(stack_A, stack_B);
}

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

void stack_A_in_two_node (t_list * stack_A)
{
	cmd_sa(stack_A);
}


void stack_A_in_three_node (t_list * stack_A) // 다시 재검토
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

void stack_A_B_setting (t_list * stack_A, t_list * stack_B)
{
	const int	min_val = 2;
	const int	except = 4;
	const int	max_val = stack_A->size;
	int			min_pivot;
	int			max_pivot;

	min_pivot = (max_val - except) / 3 + except - 1; // 3
	max_pivot = (max_val - except) / 3 * 2 + except - 1; // 4
	move_range_to_b(min_val, min_pivot, stack_A, stack_B); // (2, 3]
	move_range_to_b(min_pivot, max_pivot, stack_A, stack_B);// (3, 4]
	move_range_to_b(max_pivot, max_val - 1 - 1, stack_A, stack_B); // (4, 5]
	find_max_idx(stack_A, stack_B);
	stack_A_in_three_node (stack_A);
	cmd_pa(stack_B, stack_A);
}

void stack_A_round (t_list * stack_A, int * temp_total) //idx(val) < stack_A->idx_size / 2 == rrb
{
	t_node * A_temp;
	int idx;

	idx = 0;
	A_temp = stack_A->head->next;
	temp_total[1] = 0; //ra
	temp_total[2] = 0; //rra
	// index[0] ra[1] rra[2] rb[3] rrb[4] rr[5] rrr[6] cmd_cnt[7]
	if (A_temp->value > temp_total[0] && A_temp->prev->value < temp_total[0])
		return;
	while (!(A_temp->value < temp_total[0] && A_temp->next->value > temp_total[0]))
	{
		idx++;
		A_temp = A_temp->next;
	}
	while (A_temp != stack_A->head->next->prev)
	{
		if (idx < stack_A->size / 2)
		{	
			A_temp = A_temp->prev;
			temp_total[1]++;
			//cmd_ra(stack_A);
		}
		else
		{	
			A_temp = A_temp->next;
			temp_total[2]++;
			//cmd_rra(stack_A);
		}
	}
}

void stack_B_round (t_list * stack_B, t_node * temp, int * temp_total, int idx)
{
	temp_total[3] = 0;
	temp_total[4] = 0;
	// index[0] ra[1] rra[2] rb[3] rrb[4] rr[5] rrr[6] cmd_cnt[7]
	while (temp != stack_B->head->next)
	{
		if (idx < stack_B->size / 2)
		{
			temp = temp->prev;
			temp_total[3]++;
			//cmd_rb(stack_B);
		}
		else
		{
			temp = temp->next;
			temp_total[4]++;
			//cmd_rrb(stack_B);
		}
	}
}

void rr_compare (int * temp_total)
{
	if (temp_total[1] == temp_total[3]) //ra[0], rb[3], rr[5]
	{
		temp_total[5] = temp_total[1];
		temp_total[1] = 0;
		temp_total[3] = 0;
	}
	else if (temp_total[1] > temp_total[3])
	{
		temp_total[5] = temp_total[3];
		temp_total[1] = temp_total[1] - temp_total[3];
		temp_total[3] = 0;
	}
	else
	{	
		temp_total[5] = temp_total[1];
		temp_total[3] = temp_total[3] - temp_total[1];
		temp_total[1] = 0;
	}	
}

void rrr_compare (int * temp_total) //rra[2], rrb[4], rrr[6]
{
	if (temp_total[2] == temp_total[4])
	{
		temp_total[6] = temp_total[2];
		temp_total[2] = 0;
		temp_total[4] = 0;
	}
	else if (temp_total[2] > temp_total[4])
	{
		temp_total[6] = temp_total[4];
		temp_total[2] = temp_total[2] - temp_total[4];
		temp_total[4] = 0;
	}
	else
	{	
		temp_total[6] = temp_total[2];
		temp_total[4] = temp_total[4] - temp_total[2];
		temp_total[2] = 0;
	}	
}

void cmd_count (int * temp_total)
{
	int i;
	int cmd_cnt;
	
	i = 1;
	cmd_cnt = 0;
	while (i < 7)
	{
		cmd_cnt += temp_total[i];
		i++;
	}
	temp_total[7] = cmd_cnt;
}

void copy_cmd(int * temp_total, int * min_cmd)
{
	int i;

	i = 0;
	while (i < 8)
	{
		min_cmd[i] = temp_total[i];
		i++;
	}	
}

void cnt_optimization (int * temp_total, int * min_cmd)
{
	rr_compare(temp_total);
	rrr_compare(temp_total);
	cmd_count(temp_total);
	if (temp_total[7] < min_cmd[7])
		copy_cmd(temp_total, min_cmd);
}

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
	// printf("call one_r_c\n");
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

/*

B_stack - size/2 < val -> rb
A_stack - size/2 < val -> ra

ra rb
1	2 = 1 - 2 = 1 / rr 1 나머지 큰 수 (rb) 1
2	1
3	1 = 작은 만큼 (1) rr, 차이 만큼 (3 - 1) (ra 2)
1	3

ra rb중 큰 수가 (ra, rb) 명령어, ra-rb 명령어는 ra/rb 차이 만큼  / 작은 수만큼 rr

*/