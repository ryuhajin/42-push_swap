/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:20 by dayou             #+#    #+#             */
/*   Updated: 2023/07/28 19:16:28 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap.h"

int make_stack (t_list * stack_A, t_list * stack_B) //stack b make
{
	stack_A = make_list();
	stack_B = make_list();
	if (stack_A == NULL || stack_B == NULL)
		return failed;
	return success;
}

void cmd_s (t_list * stack) // stack a top index 0, 1 chage
{
	t_node * index_0;
	t_node * index_1;

	if (stack->size < 2)
		return;
	index_0 = stack->head->next;
	index_1 = stack->head->next->next;
	if (stack->size != 2)
		prev_move_node(stack, index_1, index_1, index_0);
	stack->head->next = index_1;
}

void cmd_ss (t_list * stack_a, t_list * stack_b) //sa, sb 
{
	cmd_s(stack_a);
	cmd_s(stack_b);
}

void cmd_pa (t_list * stack_b, t_list * stack_a) // b top -> a top 
{
	t_node * stack_b_top;
	if (stack_b->size == 0)
		return;
	stack_b_top = push_Back(stack_a, stack_b->head->next->value);
	stack_a->head->next = stack_b_top;
	remove_node(stack_b, stack_b->head->next);
}

void cmd_pb (t_list * stack_a, t_list * stack_b) // a top -> b top
{
	t_node * stack_a_top;
	if (stack_a->size == 0)
		return;
	stack_a_top = push_Back(stack_b, stack_a->head->next->value);
	stack_b->head->next = stack_a_top;
	remove_node(stack_a, stack_a->head->next);
}

void cmd_ra (t_list * stack_a) // index 0 -> index last
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->next;
}

void cmd_rb (t_list * stack_b) // index 0 -> index last
{
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->next;
}

void cmd_rr (t_list * stack_a, t_list * stack_b) // ra, rb
{
	cmd_ra(stack_a);
	cmd_rb(stack_b);
}

void cmd_rra (t_list * stack_a) // index last -> index 0
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->prev;
}

void cmd_rrb (t_list * stack_b) // index last -> index 0
{
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->prev;
}

void cmd_rrr (t_list * stack_a, t_list * stack_b) //rra, rrb
{
	cmd_rra(stack_a);
	cmd_rrb(stack_b);
}
