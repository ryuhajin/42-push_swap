/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:19:12 by dayou             #+#    #+#             */
/*   Updated: 2023/07/22 18:04:14 by dayou            ###   ########.fr       */
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

int list_ready(int argc, char ** split[])
{
    long long temp;
	int i;
	int j;
	
	i = 0;
	j = 0;
	while (i < argc-1)
	{
		while (split[i][j])
		{
			temp = ft_atoi(split[i][j]);
			if (temp < INT_MIN || INT_MAX < temp)
			{	
				//split_clear(argc, split);
				//fclear_list(list);
				return failed;
			}
		}
	}
}
