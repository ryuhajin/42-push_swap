/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:19:42 by dayou             #+#    #+#             */
/*   Updated: 2023/08/30 19:11:47 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./headers/push_swap.h"

int	split_start(int argc, char **argv, char **splits[])
{
	char	**temp;
	int		i;
	int		j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		temp = ft_split(argv[i], ' ');
		if (temp == NULL)
			return (failed);
		splits[j] = temp;
		i++;
		j++;
	}
	splits[j] = NULL;
	return (success);
}

void	all_clear(int argc, char **splits[], t_list *stack_a, t_list *stack_b)
{
	split_clear(argc, splits);
	fclear_list(stack_a);
	fclear_list(stack_b);
}

int	atoi_start(int argc, char **splits[], t_list *stack_a)
{
	int	i;
	int	j;

	i = 0;
	while (splits[i])
	{
		j = 0;
		if (splits[i][j] == NULL)
			return (failed);
		while (splits[i][j])
		{
			if (!number_check(splits[i][j]))
				return (failed);
			if (!same_range_check(splits[i][j], stack_a))
				return (failed);
			j++;
		}
		i++;
	}
	split_clear(argc, splits);
	return (success);
}

int	input_check(int argc, char *argv[], t_list *stack_a, t_list *stack_b)
{
	char	***splits;

	splits = malloc(sizeof(char *) * argc);
	if (split_start(argc, argv, splits))
	{
		if (atoi_start(argc, splits, stack_a))
		{
			return (success);
		}
	}
	all_clear(argc, splits, stack_a, stack_b);
	return (failed);
}
