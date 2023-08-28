/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 19:44:57 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int make_stack (t_list ** stack_A, t_list ** stack_B) //stack b make
{
	*stack_A = make_list();
	if (stack_A == NULL)
		return failed;
	*stack_B = make_list();
	if (stack_B == NULL)
	{
		fclear_list(*stack_A);
		return failed;
	}
	return success;
}

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

void cmd_ra (t_list * stack_a) // index 0 -> index last
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->next;
	write(1, "ra\n", 3);
}

void cmd_rb (t_list * stack_b) // index 0 -> index last
{
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->next;
	write(1, "rb\n", 3);
}

void cmd_rr (t_list * stack_a, t_list * stack_b) // ra, rb
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->next;
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->next;
	write(1, "rr\n", 3);
}

void cmd_rra (t_list * stack_a) // index last -> index 0
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->prev;
	write(1, "rra\n", 4);
}

void cmd_rrb (t_list * stack_b) // index last -> index 0
{
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->prev;
	write(1, "rrb\n", 4);
}

void cmd_rrr (t_list * stack_a, t_list * stack_b) //rra, rrb
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->prev;
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->prev;
	write(1, "rrr\n", 4);
}
