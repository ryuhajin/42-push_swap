/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:51:49 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

void cmd_sa (t_list * stack_A) // stack_A a top index 0, 1 chage
{
	t_node * index_0;
	t_node * index_1;

	if (stack_A->size < 2)
		return;
	index_0 = stack_A->head->next;
	index_1 = stack_A->head->next->next;
	if (stack_A->size != 2)
		prev_move_node(stack_A, index_1, index_1, index_0);
	stack_A->head->next = index_1;
	write(1, "sa\n", 3);
}

void cmd_sb (t_list * stack_B) // stack_B a top index 0, 1 chage
{
	t_node * index_0;
	t_node * index_1;

	if (stack_B->size < 2)
		return;
	index_0 = stack_B->head->next;
	index_1 = stack_B->head->next->next;
	if (stack_B->size != 2)
		prev_move_node(stack_B, index_1, index_1, index_0);
	stack_B->head->next = index_1;
	write(1, "sb\n", 3);
}

void cmd_ss (t_list * stack_a, t_list * stack_b) //sa, sb 
{
	cmd_sa(stack_a);
	cmd_sb(stack_b);
	write(1, "ss\n", 3);
}

void cmd_pa (t_list * stack_b, t_list * stack_a) // b top -> a top 
{
	t_node * stack_b_top;
	if (stack_b->size == 0)
		return;
	stack_b_top = push_Back(stack_a, stack_b->head->next->value);
	stack_a->head->next = stack_b_top;
	remove_node(stack_b, stack_b->head->next);
	write(1, "pa\n", 3);
}

void cmd_pb (t_list * stack_a, t_list * stack_b) // a top -> b top
{
	t_node * stack_a_top;
	if (stack_a->size == 0)
		return;
	stack_a_top = push_Back(stack_b, stack_a->head->next->value);
	stack_b->head->next = stack_a_top;
	remove_node(stack_a, stack_a->head->next);
	write(1, "pb\n", 3);
}
