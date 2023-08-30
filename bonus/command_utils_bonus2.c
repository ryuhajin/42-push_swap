/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils_bonus2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:36:06 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 17:14:39 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

void	checker_cmd_ra(t_list *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->next;
}

void	checker_cmd_rb(t_list *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->next;
}

void	checker_cmd_rr(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->next;
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->next;
}
