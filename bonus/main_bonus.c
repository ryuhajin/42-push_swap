/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:11:44 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 20:25:53 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_list	*checker_stack_a;
	t_list	*checker_stack_b;

	if (argc == 1)
		return (0);
	if (!make_stack(&checker_stack_a, &checker_stack_b))
		return (0);
	if (!input_check(argc, argv, checker_stack_a, checker_stack_b))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!line_check(checker_stack_a, checker_stack_b))
		return (0);
	if (checker_stack_b->size != 0 || !(checker_sort_check(checker_stack_a)))
	{
		write(1, "KO\n", 3);
		fclear_2_lists(checker_stack_a, checker_stack_b);
		return (0);
	}
	write(1, "OK\n", 3);
	fclear_2_lists(checker_stack_a, checker_stack_b);
	return (0);
}
