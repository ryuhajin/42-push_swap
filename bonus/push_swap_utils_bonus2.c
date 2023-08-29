/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus2.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/29 17:13:20 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 20:35:08 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

char	*ft_strdup(char *s1)
{
	char	*line;
	size_t	size;
	size_t	idx;

	size = 0;
	while (s1[size])
		size++;
	line = (char *)malloc(sizeof(char) * (size + 1));
	if (line == NULL)
		return (NULL);
	idx = 0;
	while (s1[idx])
	{
		line[idx] = s1[idx];
		idx++;
	}
	line[size] = '\0';
	return (line);
}

char	*ft_strjoin(char *s1, char *s2, ssize_t size)
{
	ssize_t	len;
	ssize_t	idx;
	char	*line;

	len = 0;
	while (s1[len])
		len++;
	line = (char *)malloc(sizeof(char) * (len + size) + 1);
	if (line == NULL)
	{
		free(s1);
		return (NULL);
	}
	line[len + size] = '\0';
	ft_strlcpy(line, s1);
	idx = 0;
	while (idx < size)
	{
		line[len + idx] = s2[idx];
		idx++;
	}
	free(s1);
	return (line);
}

size_t	ft_strlcpy(char *dest, char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (i);
}

ssize_t	find_newline(char *buff, ssize_t *size)
{
	ssize_t	idx;

	idx = 0;
	while (buff[idx])
	{
		if (buff[idx] == '\n')
		{
			*size = idx;
			return (make_new_line);
		}
		idx++;
	}
	*size = idx;
	return (no_new_line);
}

ssize_t	remainder_find_n(int fd, char **line, char remainder[][BUFFER_SIZE + 1])
{
	ssize_t	size;
	ssize_t	flag;

	*line = ft_strdup("");
	if (*line == NULL)
		return (line_malloc_failed);
	flag = find_newline(remainder[fd], &size);
	if (flag == make_new_line)
	{
		*line = ft_strjoin(*line, remainder[fd], size + 1);
		if (*line == NULL)
			return (line_malloc_failed);
		ft_strlcpy(remainder[fd], &(remainder[fd][size + 1]));
		return (make_new_line);
	}
	*line = ft_strjoin(*line, remainder[fd], size);
	if (*line == NULL)
		return (line_malloc_failed);
	remainder[fd][0] = '\0';
	return (no_new_line);
}
