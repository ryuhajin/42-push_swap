/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 17:00:16 by dayou             #+#    #+#             */
/*   Updated: 2023/08/23 21:54:59 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

void A_to_B (t_list * stack_A, t_list * stack_B)
{
	const int min_val = 2;
	const int max_val = stack_A->size;
	int min_pivot;
	int max_pivot;

	// size = 3n + a (0 <= a <= 2) 0 1 2 / 3 / 4 / 5
	// min_pivot = (stack_) 6 + 3 / 2  = 2
	// max_pivot = 2n 
	min_pivot = (max_val - 3) / 3 + 3 - 1; // 3
	max_pivot = (max_val - 3) / 3 * 2 + 3 - 1; // 4
	// min_to_stack_B(min_pivot, cnt, stack_A, stack_B);
	move_range_to_b(min_val, min_pivot, stack_A, stack_B); // (2, 3]
	move_range_to_b(min_pivot, max_pivot, stack_A, stack_B);// (3, 4]
	move_range_to_b(max_pivot, max_val - 1, stack_A, stack_B); // (4, 5]
	// printf("min end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	// middle_to_stack_B(max_pivot + 3, cnt, stack_A, stack_B);
	// printf("middle end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	// max_to_stack_B(base_pivot, cnt, stack_A, stack_B);
	// printf("max end\n");
	// print_list(stack_A);
	// print_list(stack_B);
	// stack_A_in_three_node (stack_A);
	// print_list(stack_A);
	// print_list(stack_B);
}

// 1. 30개가 주어졌을 때, 3분할을 할 것임.
// 2. 정렬을 함
	// 2-1. 정렬은 퀵소트로 구현
// 3. 피봇을 구함
	// 3-1. 1/3 2/3 지점에 있는 값을 기준으로 함
// 4. A에서 B로 옮김
	// 4-1. 3에서 구해진 피봇을 통해서 작은 (구간의 값들을 A에서 B로 옮김) 
		// 4-1-1. 해당 구간의 값을 옮기는 방법은?
		// 구간의 최대값 (pivot)
		// 숫자의 갯수 (cnt)
		// 카운터를 따로 둠 (move_cnt = 0)
		// 반복
			// move_cnt가 cnt와 동일해질때까지 반복
			// 구간에 해당하는 값이면 옮김 -> move_cnt 1증가
			// 	아니면, rotate
	// 4-2. 3에서 구해진 피봇을 통해서 중간 (구간의 값들을 A에서 B로 옮김) 
	// 4-3. 3에서 구해진 피봇을 통해서 큰 (구간의 값들을 A에서 B로 옮김) 
// 5. 그리디로 할것임
	// 5-1. 그리드는 어떻게?
// 1 - 30
// pivot 1 - pivot 10
// 			 min_pivot : cnt (10: 10) (10까지 10개만큼)
// pivot 11 - pivot 20
// 			 min_pivot : cnt (20: 10) (20까지 10개만큼)
// pivot 21 - pivot 30
// 			 min_pivot : cnt (30: 10) (30까지 10개만큼)
// min_pivot를 포함, min_pivot까지 cnt개 만큼 A에서 B(top)로 옮기는 함수
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

void stack_A_in_three_node (t_list * stack_A)
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
