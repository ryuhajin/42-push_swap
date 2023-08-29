/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils_bonus3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:40:17 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:55:23 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

void checker_cmd_rra (t_list * stack_a) // index last -> index 0
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->prev;
}

void checker_cmd_rrb (t_list * stack_b) // index last -> index 0
{
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->prev;
}

void checker_cmd_rrr (t_list * stack_a, t_list * stack_b) //rra, rrb
{
	if (stack_a->size < 2)
		return;
	stack_a->head->next = stack_a->head->next->prev;
	if (stack_b->size < 2)
		return;
	stack_b->head->next = stack_b->head->next->prev;
}
