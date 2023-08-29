/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:11:44 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:54:43 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

int main (int argc, char * argv[])
{
	t_list * checker_stack_A;
	t_list * checker_stack_B;
	
	if (argc == 1)
		return 0;
	if (!make_stack(&checker_stack_A, &checker_stack_B))
		return 0;
	if (!input_check(argc, argv, checker_stack_A, checker_stack_B))
	{
		write(1, "Error\n", 6);
		return 0;
	}
	if (!line_check(checker_stack_A, checker_stack_B))
	{
		fclear_2_lists(checker_stack_A, checker_stack_B);
		return 0;
	}
	if (checker_stack_B->size != 0 || !(checker_sort_check(checker_stack_A)))
	{	
		print_list(checker_stack_A);
		print_list(checker_stack_B);
		write(1, "KO\n", 3);
		fclear_2_lists(checker_stack_A, checker_stack_B);
		return 0;
	}
	write(1, "OK\n", 3);
	fclear_2_lists(checker_stack_A, checker_stack_B);
	return 0;
}
