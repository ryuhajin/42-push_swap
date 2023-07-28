/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:19:12 by dayou             #+#    #+#             */
/*   Updated: 2023/07/28 21:21:44 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long long	ft_atoi(const char *str)
{
	long long	numbers;
	int			minus;
	size_t		i;

	numbers = 0;
	minus = 1;
	i = 0;
	while ((9 <= str[i] && str[i] <= 13) || str[i] == 32)
		i++;
	if ('-' == str[i] || '+' == str[i])
	{
		if ('-' == str[i])
			minus = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		numbers *= 10;
		numbers += str[i] - '0';
		i++;
	}
	return (numbers * minus);
}

int search_same_value(t_list * list, int value)
{
	if (list->size == 0)
		return success;
	if (search_node(list, value))
		return failed;
	return success;
}

int list_ready(int argc, char ** split[], t_list * list)
{
    long long temp;
	int i;
	int j;
	
	i = 0;
	while (i < argc-1)
	{
        j = 0;
		while (split[i][j])
		{
			temp = ft_atoi(split[i][j]);
			if (temp < INT_MIN || INT_MAX < temp || !search_same_value(list, (int)temp))
			{
				split_clear(argc, split);
				fclear_list(list);
				return failed;
			}
            push_Back(list, (int)temp);
            j++;
		}
        i++;
	}
	split_clear(argc, split);
	return success;
}
