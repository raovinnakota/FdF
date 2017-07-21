/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:22:15 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/20 17:43:30 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_row(char *str)
{
	char **row;

	row = ft_strsplit(str, 32);
	return (row);
}

void	set_dimensions(t_map *map, char **arr)
{
	int height;
	int width;

	width = ft_arrsize(get_row(arr[0]));
	height = ft_arrsize(arr);
	printf("width:%d\nheight:%d\n", width, height);
	map->map_x = width;
	map->map_y = height;
	map->map_area = (map->map_x * map->map_y);
}

/*
t_map	new_map(char **arr)
{
	t_map ret;

	return (ret);
}
*/

int		main(int ac, char **av)
{
	int fd;
	t_map map;
	char **arr;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	set_dimensions(&map, arr);
	printf("width:%d\nheight%d\narea:%d\n", map.map_x, map.map_y, map.map_area);
	return (0);
}
