/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_input_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:17:39 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 20:26:15 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

int	checker_sort_check(t_list *checker_stack_a)
{
	t_node	*temp;

	temp = checker_stack_a->head->next;
	if (temp->value > checker_stack_a->head->next->next->value)
		return (failed);
	temp = checker_stack_a->head->next->next;
	while (temp != checker_stack_a->head->next->prev)
	{
		if (temp->value > temp->next->value)
			return (failed);
		temp = temp->next;
	}
	return (success);
}

int	line_check(t_list *checker_stack_a, t_list *checker_stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line != NULL)
	{
		if (!checker_cmd_check(line, checker_stack_a, checker_stack_b))
		{
			write(2, "Error\n", 6);
			free(line);
			fclear_2_lists(checker_stack_a, checker_stack_b);
			return (failed);
		}
		free(line);
		line = get_next_line(0);
	}
	return (success);
}
