/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 16:47:49 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:26:16 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "./headers/push_swap.h"

void split_free(char ** split)
{
	int i;
	i = 0;
	while(split[i])
	{	
		free(split[i]);
		i++;
	}
	free(split[i]);
	free(split);
}

void split_clear(int argc, char ** split[]) //스플릿 전체 삭제
{
	int i;
	i = 0;
	while(i < argc-1)
	{
		split_free(split[i]);
		i++;
	}
}

size_t	count_word(char const *str, char c)
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

void	copy_words(char **split, char const *str, char c, size_t size)
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

size_t	alloc_words(char **split, char const *str, char c, size_t size)
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
