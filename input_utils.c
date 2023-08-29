/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:57:52 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int split_start(int argc, char ** argv, char ** splits[])
{
	char ** temp;
    int i;
    int j;

    i = 1;
    j = 0;
    while (i < argc)
    {
        temp = ft_split(argv[i], ' ');
        if(temp == NULL)
            return failed;
		splits[j] = temp;
        i++;
        j++;
    }
    splits[j] = NULL;
    return success;
}

void all_clear (int argc, char ** splits[], t_list * stack_A, t_list * stack_B)
{
	split_clear(argc, splits);
	fclear_list(stack_A);
	fclear_list(stack_B);
}

int atoi_start (int argc, char ** splits[], t_list * stack_A)
{
	int i;
	int j;

	i = 0;
	while (splits[i])
	{
		j = 0;
		while (splits[i][j])
		{
			if (!number_check(splits[i][j]))
				return failed;
			if (!same_range_check(splits[i][j], stack_A))
				return failed;
			j++;
		}
		i++;
	}
	split_clear(argc, splits);
	return success;
}

int input_check (int argc, char * argv[], t_list * stack_A, t_list * stack_B)
{
	char ** splits[argc -1];
	
	if (split_start(argc, argv, splits))
	{
		if (atoi_start(argc, splits, stack_A))
		{
			return success;
		}
	}
	all_clear(argc, splits, stack_A, stack_B);
	return failed;
}
