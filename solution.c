/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/24 22:21:02 by dayou            ###   ########.fr       */
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

int stack_A_size_too_small (t_list * stack_A)
{
	if (stack_A->size > 3)
		return 1;
	else if (stack_A->size == 2)
		stack_A_in_two_node(stack_A);
	else if (stack_A->size == 3)
		stack_A_in_three_node(stack_A);
	return 0;
}

void stack_A_B_setting (t_list * stack_A, t_list * stack_B)
{
	const int min_val = 2;
	const int max_val = stack_A->size;
	int min_pivot;
	int max_pivot;

	printf("c");
	min_pivot = (max_val - 3) / 3 + 3 - 1; // 3
	max_pivot = (max_val - 3) / 3 * 2 + 3 - 1; // 4
	move_range_to_b(min_val, min_pivot, stack_A, stack_B); // (2, 3]
	move_range_to_b(min_pivot, max_pivot, stack_A, stack_B);// (3, 4]
	move_range_to_b(max_pivot, max_val - 2, stack_A, stack_B); // (4, 5]
	find_max_idx(stack_A, stack_B);
	stack_A_in_three_node (stack_A);
	cmd_pa(stack_B, stack_A);
}

// void total_count (t_list * stack_B, t_list * stack_A)
// {
// 	int max_idx;
// 	t_node * temp;
	
// 	temp = stack_B->head->next;
// 	max_idx = 2;
// 	while (stack_B->size > 0)
// 	{
		
// 	}
// }

// void solution (t_list * stack_B, t_list * stack_A, int idx_size)
// {
// 	int cnt;
// 	t_node * temp;

// 	temp = stack_B->head->next;
// 	idx_size = idx_size / 2;
// 	cnt = 0;
// 	while (stack_A->head->next->value > temp->value)
// 	{
// 		if (temp->value > idx_size)
// 			cmd_rrb(stack_B);
// 		else
// 			cmd_rb(stack_B);
// 	}
// }

// void B_round_cnt (t_list * stack_B, t_list * stack_A)
// {
// 	t_node * temp;
// 	int min_cnt;
// 	int memo[1][1];

// 	temp = stack_B->head->next;
	
// 	while (temp != stack_B->head->next)
// 	{
		
// 	}
// }

// void A_round_cnt (t_list * stack_A, t_list * stack_B)
// {
// 	int last_idx;
// 	int head_idx;
	
// 	last_idx = stack_A->head->next->prev->value; //2
// 	head_idx = stack_A->head->next->value; //0

// 	while ()
// }
