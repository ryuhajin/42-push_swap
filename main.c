/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/21 20:16:46 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// void	check_leak(void)
// {
// 	system("leaks --list push_swap");
// }


//input ++ -- 처리!!
int main(int argc, char * argv[])
{
    char ** split[argc -1];
    t_list * stack_A = make_list();
	// t_list * stack_B = make_list();
	//list->size == 1 return;
	//list->size == 2 / == 3 hard cord
	if (argc == 1)
		return 0;
	// if (!make_stack(stack_A, stack_B))
	// 	return 0;
    if (!input_ready(argc, argv, split, stack_A))
	{
		write(1, "Error\n", 6); //표준출력으로 출력하기.
		return 0;
	}
	print_list(stack_A);
	stack_A_sort(stack_A);
	// print_list(stack_B);
	// fclear_list(list);
    // atexit(check_leak);
    return 0;
}
