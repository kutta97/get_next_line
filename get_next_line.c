/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyejinyang <hyejinyang@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:28:03 by hyyang            #+#    #+#             */
/*   Updated: 2021/04/04 13:01:59 by hyejinyang       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	ft_containg_new_line(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static void	ft_save_after_newline(char **save, int nl)
{
	char	*tmp;
	size_t	len;

	len = ft_strlen(*save + nl + 1);
	if (len == 0)
	{
		free(*save);
		*save = 0;
		return ;
	}
	tmp = ft_strdup(*save + nl + 1);
	free(*save);
	*save = tmp;
	return ;
}

static int	ft_output(char **save, char **line, int r)
{
	int nl;

	if (r < 0)
		return (-1);
	if (*save)
	{
		if ((nl = ft_containg_new_line(*save)) >= 0)
		{
			(*save)[nl] = '\0';
			*line = ft_strdup(*save);
			ft_save_after_newline(save, nl);
			return (1);
		}
		else
		{
			*line = *save;
			*save = 0;
			return (0);
		}
	}
	*line = ft_strdup("");
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*save[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	int			r;

	if (fd < 0 || line == 0 || BUFFER_SIZE <= 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
		if (ft_containg_new_line(save[fd]) >= 0)
			break ;
	}
	return (ft_output(&save[fd], line, r));
}
