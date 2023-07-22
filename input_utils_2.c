/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <dayou@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:26:11 by dayou             #+#    #+#             */
/*   Updated: 2023/07/22 14:29:26 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	count_word(char const *str, char c)
{
	size_t	idx;
	size_t	size;

	idx = 0;
	size = 0;
	while (str[idx])
	{
		if (str[idx] != c && (str[idx + 1] == c || str[idx + 1] == '\0'))
			size++;
		idx++;
	}
	return (size);
}

static void	copy_words(char **split, char const *str, char c, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	idx;

	i = 0;
	j = 0;
	idx = 0;
	while (i < size)
	{
		j = 0;
		while (str[idx] == c)
			idx++;
		while (str[idx] != c && str[idx])
		{
			split[i][j] = str[idx];
			j++;
			idx++;
		}
		split[i][j] = 0;
		i++;
	}
}

static size_t	alloc_words(char **split, char const *str, char c, size_t size)
{
	size_t	i;
	size_t	idx;
	size_t	strlen;
	char	*new_str;

	i = 0;
	idx = 0;
	strlen = 0;
	while (i < size)
	{
		strlen = 0;
		while (str[idx] == c)
			idx++;
		while (str[idx] != c && str[idx])
		{
			idx++;
			strlen++;
		}
		new_str = (char *)malloc(sizeof(char) * (strlen + 1));
		split[i] = new_str;
		if (split[i] == 0)
			return (i + 1);
		i++;
	}
	return (0);
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
