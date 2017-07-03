/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/28 17:18:08 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/03 15:16:13 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**fill_map(int fd)
{
	int		y;
	char	**line;

	y = 0;
	line = (char**)malloc(sizeof(char*) * UINT_MAX);
	while (get_next_line(fd, &line[y]) != 0)
		y++;
	return (line);
}

/*
int		validate(char **map)
{
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(map[0]);
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		y;
	int		fd;
	char	**line;

	if (ac < 2)
		return (0);
	y = 0;
	fd = open(av[1], O_RDONLY);
	line = fill_map(fd);
	printf("%d\n", validate(line));
	while(line[y])
	{
		printf("%s\n", line[y]);
		y++;
	}
	return(0);
}
*/
