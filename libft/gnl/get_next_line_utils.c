/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 17:18:52 by ade-la-c          #+#    #+#             */
/*   Updated: 2021/09/14 16:10:32 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int					ft_strlenn(const char *str)
{
	int				i;

	i = 0;
	while (str && str[i])
		i++;
	return (i);
}

char				*ft_strcpyy(char *dest, const char *src)
{
	int	i;

	i = -1;
	if (!src)
		return (NULL);
	while (src[++i])
		dest[i] = src[i];
	dest[i] = '\0';
	return (dest);
}

char				*ft_strjoinn(char *s1, char *s2, int b)
{
	int				i;
	int				j;
	char			*string;
	char			s1_new[ft_strlenn(s1) + 1];
	char			s2_new[ft_strlenn(s2) + 1];

	i = -1;
	j = -1;
	if (!s1)
		return (ft_strdupp(s2));
	ft_strcpyy(s1_new, s1);
	free(s1);
	ft_strcpyy(s2_new, s2);
	if (b == 1)
		free(s2);
	b = ft_strlenn(s1_new) + ft_strlenn(s2_new);
	if (!(string = (char *)malloc(sizeof(char) * (b + 1))))
		return (NULL);
	while (++i < ft_strlenn(s1_new))
		string[i] = s1_new[i];
	while (++j < ft_strlenn(s2_new))
		string[i + j] = s2_new[j];
	string[b] = '\0';
	return (string);
}

char				*ft_strdupp(const char *s1)
{
	int				i;
	char			*string;
	int				size;

	i = 0;
	size = ft_strlenn(s1);
	string = NULL;
	if (!(string = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		string[i] = s1[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

char				*ft_substrr(char *s, int start, int len, char *str)
{
	char			*string;
	int				i;

	i = -1;
	if (!s)
		return (NULL);
	if (start > ft_strlenn(s))
	{
		free(str);
		str = NULL;
		return (ft_strdupp(""));
	}
	if (start + len > ft_strlenn(s))
		len = ft_strlenn(s) - start;
	if (!(string = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (++i < len)
		string[i] = s[start + i];
	free(str);
	str = NULL;
	string[i] = '\0';
	return (string);
}
