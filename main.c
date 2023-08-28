/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 21:40:57 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> // 나중에 삭제
#include "push_swap.h"

// void	check_leak(void)
// {
// 	system("leaks --list push_swap");
// }

//./push_swap " " <- Error // "-100 100" <- input error로 나옴 확인해봐야함
// 인풋 스플릿을 먼저 해서 ' ' 는  다 자르기

int main(int argc, char * argv[])
{
    t_list * stack_A;
	t_list * stack_B;

	if (argc == 1)
		return 0;
	if (!make_stack(&stack_A, &stack_B))
		return 0;
    if (!input_check(argc, argv, stack_A, stack_B))
	{
		write(1, "Error\n", 6);
		return 0;
	}
	if (!stack_A_sort(stack_A))
	{
		fclear_list(stack_B);
		return 0;
	}
	if (!stack_A_size_too_small(stack_A, stack_B))
		return 0;
	solution_commander(stack_A, stack_B);
	// check_leak();
    return 0;
}
