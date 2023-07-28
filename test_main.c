/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/28 15:57:30 by dayou             #+#    #+#             */
/*   Updated: 2023/07/28 19:15:23 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

int main(void)
{
	t_list * stack_a = make_list();
	t_list * stack_b = make_list();
	
	push_Back(stack_a, 1);
		push_Back(stack_a, 2);
			push_Back(stack_a, 3);
						push_Back(stack_a, 4);

	push_Back(stack_b, 100);
	push_Back(stack_b, 1000);
	push_Back(stack_b, 1000000);

	cmd_rra(stack_a);
	print_list(stack_a);
	print_list(stack_b);
}
