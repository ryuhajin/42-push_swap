/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:39:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:07:47 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	cmd_sa(t_list *stack_a)
{
	t_node	*index_0;
	t_node	*index_1;

	if (stack_a->size < 2)
		return ;
	index_0 = stack_a->head->next;
	index_1 = stack_a->head->next->next;
	if (stack_a->size != 2)
		prev_move_node(stack_a, index_1, index_1, index_0);
	stack_a->head->next = index_1;
	write(1, "sa\n", 3);
}

void	cmd_sb(t_list *stack_b)
{
	t_node	*index_0;
	t_node	*index_1;

	if (stack_b->size < 2)
		return ;
	index_0 = stack_b->head->next;
	index_1 = stack_b->head->next->next;
	if (stack_b->size != 2)
		prev_move_node(stack_b, index_1, index_1, index_0);
	stack_b->head->next = index_1;
	write(1, "sb\n", 3);
}

void	cmd_ss(t_list *stack_a, t_list *stack_b)
{
	cmd_sa(stack_a);
	cmd_sb(stack_b);
	write(1, "ss\n", 3);
}

void	cmd_pa(t_list *stack_b, t_list *stack_a)
{
	t_node	*stack_b_top;

	if (stack_b->size == 0)
		return ;
	stack_b_top = push_back(stack_a, stack_b->head->next->value);
	stack_a->head->next = stack_b_top;
	remove_node(stack_b, stack_b->head->next);
	write(1, "pa\n", 3);
}

void	cmd_pb(t_list *stack_a, t_list *stack_b)
{
	t_node	*stack_a_top;

	if (stack_a->size == 0)
		return ;
	stack_a_top = push_back(stack_b, stack_a->head->next->value);
	stack_b->head->next = stack_a_top;
	remove_node(stack_a, stack_a->head->next);
	write(1, "pb\n", 3);
}
