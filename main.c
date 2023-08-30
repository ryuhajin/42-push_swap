/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:50:30 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int	main(int argc, char *argv[])
{
	t_list	*stack_a;
	t_list	*stack_b;

	if (argc == 1)
		return (0);
	if (!make_stack(&stack_a, &stack_b))
		return (0);
	if (!input_check(argc, argv, stack_a, stack_b))
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (!stack_a_sort(stack_a))
	{
		fclear_list(stack_b);
		return (0);
	}
	if (!stack_a_size_too_small(stack_a, stack_b))
		return (0);
	solution_commander(stack_a, stack_b);
	return (0);
}
