/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:28:03 by hyyang            #+#    #+#             */
/*   Updated: 2021/02/21 23:51:30 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int ft_append_line(char *save, char **line)
{
	int	len;

	len = 0;
	while (save[fd] != '\n' && save)
}

static int	ft_output(char **save, char **line, int r, int fd)
{
	if (r < 0)
		return (-1);
	if (r == 0 && save[fd] == 0)
		return (0);
	return (ft_append_line(&save[fd], line));
}

int			get_next_line(int fd, char **line)
{
	static char	*save[FD_SIZE];
	char		buff[BUFFER_SIZE + 1];
	int			r;
	
	if (fd < 0 || line == 0)
		return (-1);
	while ((r = read(fd, buff, BUFFER_SIZE) > 0)
	{
		buff[r] = '\0';
		save[fd] = ft_strjoin(save[fd], buff);
		if(ft_strchr(save[fd], '\n'))
			break;
	}
	return (ft_output(save, line, r, fd));
}
