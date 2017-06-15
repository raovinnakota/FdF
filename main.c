/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/14 13:40:15 by rvinnako          #+#    #+#             */
/*   Updated: 2017/06/14 13:47:12 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(int ac, char **av)
{
	int	fd;
	int		i;
	char	*line;

	if (ac == 1)
		fd = 0;
	else if (ac == 2)
		fd = open(av[1], O_RDONLY);
	else
		return (2);
	i = 0;
	while(get_next_line(fd, &line) == 1)
	{
		++i;
		ft_putendl(line);
	}
	printf("i = %d\n", i);
	if (ac == 2)
		close(fd);
}
