/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 18:00:03 by yejlee            #+#    #+#             */
/*   Updated: 2021/08/18 18:14:05 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	int		fd_1;
	int		fd_2;
	int		i;
	char	*line[4096];

	i = 1;
	fd_1 = open("testfile.txt", O_RDONLY);
	fd_2 = open("testfile2.txt", O_RDONLY);
	while (1)
	{
		line[fd_1] = get_next_line(fd_1);
		printf("Line %d for fd %d: %s\n", i, fd_1, line[fd_1]);
		line[fd_2] = get_next_line(fd_2);
		printf("Line %d for fd %d: %s\n", i, fd_2, line[fd_2]);
		if (!line[fd_1] && !line[fd_2])
			return (0);
		free(line[fd_1]);
		free(line[fd_2]);
		i++;
	}
}
