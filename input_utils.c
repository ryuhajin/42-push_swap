/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/08/21 20:45:00 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int numbers_space_check(char c)
{
    if (c >= '0' && c <= '9')
        return success;
	else if (c == '-' || c == '+' || c == ' ')
	{
		return success;
	}
    return failed;
}
int split_ready(int argc, char ** argv)
{
    int i;
    int j;
	int cnt;

    i = 1;
	cnt = 0;
    if (argc == 1)
        return failed;
    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '\0')
            return failed;
        while (argv[i][j])
        {
			if (!numbers_space_check(argv[i][j]))
				return failed;
			if (argv[i][j+1] == '-' || argv[i][j+1] == '+')
				return failed;
			j++;
        }
        i++;
    }
    return success;
}

int atoi_ready(int argc, char ** argv, char ** split[])
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
		split[j] = temp;
        i++;
        j++;
    }
    split[j] = NULL;
    return success;
}

int input_ready(int argc, char ** argv, char ** split[], t_list * list)
{
    if (split_ready(argc, argv))
    {
		printf("split ok\n");
        if (atoi_ready(argc, argv, split))
        {
			printf("atoi ok\n");
            if (list_ready(argc, split, list))
			{
				printf("list ok\n");
				// print_list(list);
				return success;
			}
        }
    }
	printf("input error\n");
    return failed;
}
