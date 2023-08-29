/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:17:39 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:03:18 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

int checker_sort_check (t_list * checker_stack_A)
{
	t_node * temp;
	temp = checker_stack_A->head->next;
	if (temp->value > checker_stack_A->head->next->next->value)
		return failed;
	temp = checker_stack_A->head->next->next;
	while (temp != checker_stack_A->head->next->prev)
	{
		if (temp->value > temp->next->value)
			return failed;
		temp = temp->next;
	}
	return success;
}

int line_check (t_list * checker_stack_A, t_list * checker_stack_B)
{
	char * line;
	
	line = get_next_line(0);
	while (line != NULL)
	{
		if (!checker_cmd_check(line, checker_stack_A, checker_stack_B))
		{	
			write(1, "Error\n", 6);
			return failed;
		}
		line = get_next_line(0);
	}
	return success;
}
