/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: root <root@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/30 15:08:45 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 23:59:55 by root             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# ifndef OPEN_MAX
#  define OPEN_MAX 256
# endif

int				get_next_line(int fd, char **line);

int				ft_strlenn(const char *str);
char			*ft_strcpyy(char *dest, const char *src);
char			*ft_strjoinn(char *s1, char *s2, int b);
char			*ft_strdupp(const char *s1);
char			*ft_substrr(char *s, int start, int len, char *str);

#endif
