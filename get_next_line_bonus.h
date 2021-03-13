/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyyang <hyyang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 02:28:18 by hyyang            #+#    #+#             */
/*   Updated: 2021/03/12 23:12:34 by hyyang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif

#ifndef FD_SIZE
# define FD_SIZE 256
#endif

int		get_next_line(int fd, char **line);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strdup(char *s1);
size_t	ft_strlen(const char *s);

#endif
