/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/08/27 21:28:20 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int numbers_space_check(char c)
// {
//     if (c >= '0' && c <= '9')
//         return success;
// 	else if (c == '-' || c == '+' || c == ' ')
// 	{
// 		return success;
// 	}
//     return failed;
// }
int word_check (char * str, int i)
{
	int temp;

	temp = i;
	if (str[temp] == '\0')
		return failed;
	if (str[temp] == '+' || str[temp] == '-')
		temp++;
	if (str[temp] == ' ' || str[temp] == '+' || str[temp] == '-' || str[temp] == '\0')
		return failed;
	while (str[temp] != ' ' && str[temp] != '\0')
	{
		if (str[temp] >= '0' && str[temp] <= '9')
			temp++;
		else
			return failed;
	}
	return temp;
}

int str_check (char * argv)
{
	int i;
	int check;

	i = 0;
	while (argv[i])
	{
		check = 0;
		while(argv[i] == ' ')
			i++;
		check = word_check(argv, i);
		if (check == 0)
			return failed;
		else
			i = check;
		i++;
	}
	return success;
}

int split_ready(char ** argv)
{
    int i;
    int j;
	int cnt;

    i = 1;
	cnt = 0;
    while (argv[i])
    {
        j = 0;
        if (argv[i][j] == '\0')
            return failed;
		if (!str_check(argv[i]))
			return failed;
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
