/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:08 by dayou             #+#    #+#             */
/*   Updated: 2023/08/28 22:25:36 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"

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

ssize_t	read_file(int fd, char **line, char remainder[][BUFFER_SIZE + 1])
{
	char	buff[BUFFER_SIZE + 1];
	ssize_t	flag;
	ssize_t	size;

	flag = read(fd, buff, BUFFER_SIZE);
	while (read_EOF < flag)
	{
		buff[flag] = '\0';
		flag = find_newline(buff, &size);
		if (flag == make_new_line)
		{
			*line = ft_strjoin(*line, buff, size + 1);
			if (*line == NULL)
				return (line_malloc_failed);
			ft_strlcpy(remainder[fd], buff + (size + 1));
			return (flag);
		}
		*line = ft_strjoin(*line, buff, size);
		if (*line == NULL)
			return (line_malloc_failed);
		flag = read(fd, buff, BUFFER_SIZE);
	}
	return (flag);
}

char	*read_flag_check(ssize_t flag, char *line)
{
	if (flag == make_new_line)
		return (line);
	else if (flag == read_EOF)
	{
		if (*line != '\0')
			return (line);
		else
		{
			free(line);
			return (NULL);
		}
	}
	else if (flag == read_failed)
		free(line);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	remainder[OPEN_MAX][BUFFER_SIZE + 1];
	char		*line;
	ssize_t		flag;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	flag = remainder_find_n(fd, &line, remainder);
	if (flag == line_malloc_failed)
		return (NULL);
	if (flag == make_new_line)
		return (line);
	flag = read_file(fd, &line, remainder);
	return (read_flag_check(flag, line));
}
