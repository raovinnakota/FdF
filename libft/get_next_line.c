/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 13:04:32 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/15 13:46:01 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		add_line(char **str, char **line)
{
	char	*nl;
	char	*tmp;

	while ((nl = ft_strchr(*str, '\n')))
	{
		*line = ft_strndup(*str, (nl - *str));
		tmp = ft_strdup(nl + 1);
		free(*str);
		*str = tmp;
		return (1);
	}
	if (**str)
	{
		*line = ft_strdup(*str);
		ft_bzero(*str, (size_t)ft_strlen(*str));
		return (1);
	}
	return (0);
}

int		get_next_line(const int fd, char **line)
{
	int			bytes;
	char		*tmp;
	char		buff[BUFF_SIZE + 1];
	static char	*str[FD_MAX];

	if ((fd < 0) || (!line) || (BUFF_SIZE <= 0) || read(fd, buff, 0) < 0)
		return (-1);
	while ((bytes = read(fd, buff, BUFF_SIZE)) != 0)
	{
		if (bytes == -1)
			return (-1);
		buff[bytes] = '\0';
		if (!str[fd])
			str[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(str[fd], buff);
			free(str[fd]);
			str[fd] = tmp;
		}
	}
	if (ft_strlen(str[fd]) > 0)
		return (add_line(&str[fd], line));
	return (0);
}
