/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:35:07 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 17:15:33 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

void	cmd_rra(t_list *stack_a)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->prev;
	write(1, "rra\n", 4);
}

void	cmd_rrb(t_list *stack_b)
{
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->prev;
	write(1, "rrb\n", 4);
}

void	cmd_rrr(t_list *stack_a, t_list *stack_b)
{
	if (stack_a->size < 2)
		return ;
	stack_a->head->next = stack_a->head->next->prev;
	if (stack_b->size < 2)
		return ;
	stack_b->head->next = stack_b->head->next->prev;
	write(1, "rrr\n", 4);
}
