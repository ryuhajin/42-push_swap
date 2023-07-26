/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/20 17:40:20 by dayou             #+#    #+#             */
/*   Updated: 2023/07/22 21:31:30 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "push_swap.h"

// void	check_leak(void)
// {
// 	system("leaks --list a.out");
// }



int main(int argc, char * argv[])
{
    char ** split[argc -1];
    t_list * list;

    input_ready(argc, argv, split);
    list = make_list();
    list_ready(argc, split, list);
    // atexit(check_leak);
    return 0;
}