/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 22:26:11 by dayou             #+#    #+#             */
/*   Updated: 2023/07/26 18:02:01 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

/* 

void	check_leak(void)
{
	system("leaks --list a.out");
}

int main(int argc, char ** argv)
{
	char ** split;
	char ** splits[argc-1];
	int i = 1;
	int j = 0;
	while(i < argc)
	{
		split = ft_split(argv[i], ' ');
		splits[j] = split;
		i++;
		j++;
	}
	splits[j] = NULL;
	i = 0;
	j = 0;
	while(i < argc -1)
	{	
		j = 0;
		while(splits[i][j])
		{
			printf("%s\n", splits[i][j]);
			j++;
		}
		i++;
	}
	split_clear(argc, splits);
	atexit(check_leak);
}
*/
