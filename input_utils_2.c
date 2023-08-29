/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:26:11 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 22:16:05 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

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

long long	ft_atoi(const char *str)
{
	long long	numbers;
	int			minus;
	size_t		i;

	numbers = 0;
	minus = 1;
	i = 0;
	
	if ('-' == str[i] || '+' == str[i])
	{
		if ('-' == str[i])
			minus = -1;
		i++;
	}
	while (str[i])
	{
		numbers *= 10;
		numbers += str[i] - '0';
		i++;
	}
	return (numbers * minus);
}

char	**ft_split(char const *str, char c)
{
	size_t	size;
	char	**split;
	size_t	free_cnt;

	size = 0;
	size = count_word(str, c);
	split = (char **)malloc(sizeof(char *) * (size + 1));
	if (!split)
		return (NULL);
	split[size] = 0;
	free_cnt = alloc_words(split, str, c, size);
	if (free_cnt != 0)
	{
		while (free_cnt > 0)
		{
			free(split[free_cnt - 1]);
			free_cnt--;
		}
		free(split);
		return (NULL);
	}
	copy_words(split, str, c, size);
	return (split);
}
