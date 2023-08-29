/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:34:06 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:51:53 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap.h"

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
