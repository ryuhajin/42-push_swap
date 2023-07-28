/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/07/28 19:40:22 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

void	check_leak(void)
{
	system("leaks --list push_swap");
}

int main(int argc, char * argv[])
{
    char ** split[argc -1];
    t_list * stack_A;
	t_list * stack_B;

	if (!make_stack(stack_A, stack_B))
		return 0;
    if (!input_ready(argc, argv, split, stack_A))
	{
		printf("Error\n");
		return 0;
	}
	print_list(stack_A);
	print_list(stack_B);
	// fclear_list(list);
    atexit(check_leak);
    return 0;
}
