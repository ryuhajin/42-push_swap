/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dayou <da1712@student.42seoul.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 18:48:08 by dayou             #+#    #+#             */
/*   Updated: 2023/08/29 21:40:04 by dayou            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../headers/push_swap_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
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
