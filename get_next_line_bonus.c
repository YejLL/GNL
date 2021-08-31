/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:55:27 by yejlee            #+#    #+#             */
/*   Updated: 2021/08/31 13:51:10 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	read_file(int fd, char **data)
{
	char	buffer[BUFFER_SIZE + 1];
	char	*tmp;
	int		res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res == -1 || res == 0)
		return (0);
	buffer[res] = '\0';
	tmp = ft_strjoin(*data, buffer);
	if (tmp == NULL)
		return (0);
	free(*data);
	*data = tmp;
	return (res);
}

char	*find_newline(char **data, char *newline)
{
	int	idx;

	idx = ft_strchr(*data, '\n');
	if (idx >= 0)
	{
		return (get_newline(data, newline, idx));
	}
	return (NULL);
}

char	*get_newline(char **data, char *newline, int idx)
{
	char	*tmp;
	int		len;

	//(*data)[idx] = '\0';
	/*if (idx)
		newline = ft_strdup(*data);
	else
		newline = ft_strdup("");*/
	newline = ft_substr(*data, 0, idx + 1);
	len = ft_strlen(*data + idx + 1);
	if (len == 0)
	{
		free(*data);
		*data = NULL;
		return (newline);
	}
	tmp = ft_strdup(*data + idx + 1);
	if (!tmp)
	{
		free(tmp);
		return (NULL);
	}
	free(*data);
	*data = tmp;
	return (newline);
}

char	*after_read_all(char **data, char *newline)
{
	char	*res;
	int		i;

	i = 0;
	if (*data)
	{
		res = find_newline(data, newline);
		if (res != 0)
			return (res);
		newline = *data;
		*data = NULL;
		return (newline);
	}
	else
	{
		newline = ft_strdup("");
		while (i > -1)
		{
			if (newline[i] == '\0')
			{
				free(newline);
				return (NULL);
			}
			else
				i++;
		}
		if (newline == NULL)
			return (NULL);
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*data[4096];
	int			res;
	char		*tab;
	char		*newline;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE < 1)
		return (NULL);
	newline = 0;
	while (1)
	{
		res = read_file(fd, &data[fd]);
		if (res <= 0)
			break ;
		tab = find_newline(&data[fd], newline);
		if (tab != 0)
			return (tab);
	}
	if (res == -1 && tab == NULL)
	{
		free(*data);
		return (NULL);
	}
	return (after_read_all(&data[fd], newline));
}
