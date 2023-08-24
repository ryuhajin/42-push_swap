/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/24 22:26:50 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// void	check_leak(void)
// {
// 	system("leaks --list push_swap");
// }

//./push_swap " " <- Error // "-100 100" <- input error로 나옴 확인해봐야함
// int_max 초과 long long 범위 안 atoi 확인하기
 
int main(int argc, char * argv[])
{
    char ** split[argc -1];
    t_list * stack_A;
	t_list * stack_B;

	if (argc == 1)
		return 0;
	// if (!make_list(stack_A, stack_B))
	// {
	// 	list_clear();
	// 	return;
	// }
	stack_A = make_list();
	stack_B = make_list();
	// if (!make_stack(stack_A, stack_B))
	// 	return 0;
    if (!input_ready(argc, argv, split, stack_A))
	{
		write(1, "Error\n", 6); //표준출력으로 출력하기.
		return 0;
	}
	//list->size == 2 / == 3 hard cord
	stack_A->idx_size = stack_A->size;
	// print_list(stack_A);
	if (!stack_A_sort(stack_A))
	{
		printf("a");
		return 0;
	}
	if (!stack_A_size_too_small(stack_A))
	{
		printf("b");
		return 0;
	}
	stack_A_B_setting(stack_A, stack_B);
	// print_list(stack_B);
	// fclear_list(list);
    // atexit(check_leak);
    return 0;
}
