/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 15:56:45 by yejlee            #+#    #+#             */
/*   Updated: 2021/08/18 19:41:25 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	read_file(int fd, char **data)
{
	char	buffer[BUFFER_SIZE + 1];;
	char	*tmp;
	int		res;

	res = read(fd, buffer, BUFFER_SIZE);
	if (res <= 0)
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
	return (0);	
}

char	*get_newline(char **data, char *newline, int idx)
{
	char	*tmp;

	(*data)[idx] = '\0';
	if (idx)
		newline = ft_strdup(*data);
	else
		newline = ft_strdup("");
	if (!newline)
		return (NULL);
	tmp = ft_strdup(*data + idx + 1);
	if (!tmp)
		return (NULL);
	free(*data);
	*data = tmp;
	return (newline);
}

char	*after_read_all(char **data, char *newline)
{
	char	*res;

	if (*data)
	{
		res = find_newline(data, newline);
		if (res != 0)
			return (res);
		newline = *data;
		*data = NULL;
		return (0);
	}
	else
	{
		newline = ft_strdup("");
		if (newline == NULL)
			return (0);
		return (0);
	}
}

char	*get_next_line(int fd)
{
	static char	*data[4096];
	int			res;
	char		*tab;
	char		*newline;

	if (fd < 0 || fd > 4095 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = 0;
	while (1)
	{
		res  = read_file(fd, &data[fd]);
		if (res <= 0)
			break ;
		tab = find_newline(&data[fd], newline);
		if (tab != 0)
			return (tab);
	}
	if (res == -1 || tab == NULL) 
		return (NULL);
	return (after_read_all(&data[fd], newline));
}
