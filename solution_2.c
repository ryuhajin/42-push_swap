/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:50:25 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:26:45 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/push_swap.h"

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
