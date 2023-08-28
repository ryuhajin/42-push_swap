/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:25:46 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 22:21:45 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"
# include <stdio.h>

int main (int argc, char * argv[])
{
	t_list * checker_stack_A;
	t_list * checker_stack_B;
	char * line;
	
	if (argc == 1)
		return 0;
	if (!make_stack(&checker_stack_A, &checker_stack_B))
		return 0;
	if (!input_check(argc, argv, checker_stack_A, checker_stack_B))
	{
		write(1, "Error\n", 6);
		return 0;
	}
	if (!stack_A_sort(checker_stack_A))
	{
		fclear_list(checker_stack_B);
		return 0;
	}
	line = get_next_line(0);
}