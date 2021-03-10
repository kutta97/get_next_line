/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:28:03 by hyyang            #+#    #+#             */
/*   Updated: 2021/03/04 02:40:57 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_append_line(char **save, char **line)
{
	int		len;
	char	*tmp;

	len = 0;
	tmp = 0;
	while ((*save)[len] != '\n' && (*save)[len] != '\0')
		len++;
	if ((*save)[len] == '\n')
	{
		tmp = ft_strdup(&(*save)[len + 1]);
		(*save)[len] = '\0';
	}		
	*line = ft_strdup(*save);
	free(*save);
	*save = 0;
	if (tmp)
		ft_strdup(tmp);
	return (1);
}

static int	ft_output(char **save, char **line, int r)
{
	if (r < 0)
		return (-1);
	if (r == 0 && *save == 0)
		return (0);
	return (ft_append_line(save, line));
}

int			get_next_line(int fd, char **line)
{
	static char	*save[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	int			r;
	
	if (fd < 0 || line == 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE)) > 0)
	{
		buff[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
		if(ft_strchr(save[fd], '\n'))
			break;
	}
	return (ft_output(&save[fd], line, r));
}
