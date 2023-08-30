/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_list_utils4.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:32:59 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:13:54 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int	make_stack(t_list **stack_a, t_list **stack_b)
{
	*stack_a = make_list();
	if (stack_a == NULL)
		return (failed);
	*stack_b = make_list();
	if (stack_b == NULL)
	{
		fclear_list(*stack_a);
		return (failed);
	}
	return (success);
}

void	fclear_list(t_list *list)
{
	clear_list(list);
	free(list->head);
	list->head = NULL;
	free(list);
}

void	fclear_2_lists(t_list *list, t_list *list2)
{
	fclear_list(list);
	fclear_list(list2);
}
