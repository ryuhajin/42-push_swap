/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 23:19:12 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 17:18:53 by dayou            ###   ########.fr       */
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
