/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils_bonus3.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:40:17 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 17:14:42 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

void	checker_cmd_rra(t_list *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->prev;
}

void	checker_cmd_rrb(t_list *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->prev;
}

void	checker_cmd_rrr(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->prev;
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->prev;
}
