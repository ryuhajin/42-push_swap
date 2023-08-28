/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 20:39:14 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 4->5->1->2  // 2->1->5->4 // 


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
int number_check (char * str)
{
	int i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i] == '\0')
		return failed;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return failed;
	}
	return success;
}

void all_clear (int argc, char ** splits[], t_list * stack_A, t_list * stack_B)
{
	split_clear(argc, splits);
	fclear_list(stack_A);
	fclear_list(stack_B);
}

int search_same_value(t_list * list, int value)
{
	if (list->size == 0)
		return success;
	if (search_node(list, value))
		return failed;
	return success;
}

int same_range_check (char * str, t_list * stack_A)
{
	long long temp;
	
	temp = ft_atoi(str);
	if (temp < INT_MIN || INT_MAX < temp)
		return failed;
	else if (!search_same_value(stack_A, (int)temp))
		return failed;
	push_Back(stack_A, (int)temp);
	return success;
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


// int input_ready(int argc, char ** argv, char ** split[], t_list * list)
// {
//     if (split_ready(argc, argv))
//     {
// 		printf("split ok\n");
//         if (atoi_ready(argc, argv, split))
//         {
// 			printf("atoi ok\n");
//             if (list_ready(argc, split, list))
// 			{
// 				printf("list ok\n");
// 				// print_list(list);
// 				return success;
// 			}
//         }
//     }
// 	printf("input error\n");
//     return failed;
// }
