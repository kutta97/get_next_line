/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:28:35 by hyyang            #+#    #+#             */
/*   Updated: 2021/03/04 02:41:05 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

static size_t	ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	return (i);
}

char			*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!(s2 = (char *)malloc((ft_strlen(s1) + 1) * sizeof(char))))
		return (0);
	i = ft_strcpy(s2, s1);
	s2[i] = '\0';
	return (s2);
}

char			*ft_strjoin(char *s1, char const *s2)
{
	char	*str;
	size_t	i;

	if (!s1 && !s2)
		return (0);
	if (!s1 || !s2)
		return (!s1 ? ft_strdup(s2) : 0);
	if (!(str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1)
														* sizeof(char))))
		return (0);
	i = ft_strcpy(str, s1);
	i += ft_strcpy(str + i, s2);
	str[i] = '\0';
	free(s1);
	return (str);
}

char			*ft_strchr(const char *s, int c)
{
	char *p;

	p = (char *)s;
	while (*p != c)
	{
		if (*p == '\0')
			return (0);
		p++;
	}
	return (p);
}
