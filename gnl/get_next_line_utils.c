/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:23:47 by yejlee            #+#    #+#             */
/*   Updated: 2021/08/16 21:02:57 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return (len);
}

int	ft_strchr(const char *s, char c)
{
	int	idx;

	idx = 0;
	while (s[idx])
	{
		if (s[idx] == c)
		{
			return (idx);
		}
		idx++;
	}
	return (-1);
}

char	*ft_strdup(const char *str)
{
	int		i;
	int		len;
	char	*tmp;

	i = 0;
	len = ft_strlen(str);
	tmp = (char *)malloc(sizeof(char) * (len + 1));
	if (tmp == NULL)
		return (NULL);
	while (i < len)
	{
		tmp[i] = str[i];
		i++;
	}
	tmp[i] = 0;
	return (tmp);
}

char	*ft_strjoin(const char *str, const char *buf)
{
	int		i;
	int		j;
	int		size;
	char	*tmp;

	if (!buf)
		return (NULL);
	if (!str)
		return (ft_strdup(buf));
	size = ft_strlen(str) + ft_strlen(buf) + 1;
	tmp = (char *)malloc(sizeof(char) * size);
	if (tmp == NULL)
		return (NULL);
	i = 0;
	j = 0;
	while (str[j])
		tmp[i++] = str[j++];
	j = 0;
	while (buf[j])
		tmp[i++] = buf[j++];
	tmp[i] = 0;
	return (tmp);
}
