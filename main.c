/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/07/26 23:12:28 by dayou            ###   ########.fr       */
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
    t_list * list;

	list = make_list();
	if (list == NULL)
		return 0;
    if (!input_ready(argc, argv, split, list))
		return 0;
	print_list(list);
	// fclear_list(list);
    atexit(check_leak);
    return 0;
}
