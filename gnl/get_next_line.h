/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yejlee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 16:15:04 by yejlee            #+#    #+#             */
/*   Updated: 2021/08/18 19:41:35 by yejlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strlen(const char *s);
int		ft_strchr(const char *s, char c);
char	*ft_strdup(const char *str);
char	*ft_strjoin(const char *str, const char *buf);

int		read_file(int fd, char **data);
char	*find_newline(char **data, char *newline);
char	*get_newline(char **data, char *newline, int idx);
char	*after_read_all(char **data, char *newline);
char	*get_next_line(int fd);

#endif
