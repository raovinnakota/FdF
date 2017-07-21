/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:22:15 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/20 20:41:03 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_row(char *str)
{
	char **row;

	row = ft_strsplit(str, 32);
	return (row);
}

void 	set_line(int *int_arr, char **row)
{
	int		c_count;
	int		i_count;

	c_count = 0;
	i_count = 0;
	while (row[c_count])
	{
		int_arr[i_count] = ft_atoi(row[c_count]);
		i_count++;
		c_count++;
	}
}

void	set_dimensions(t_map *map, char **arr)
{
	int height;
	int width;

	width = ft_arrsize(get_row(arr[0]));
	height = ft_arrsize(arr);
	map->map_x = width;
	map->map_y = height;
	map->map_area = (map->map_x * map->map_y);
}

/*
int		**get_int_map(char **map)
{
	int		i;
	int		**ret;
	char	**temp;

	i = 0;
	ret = (int**)malloc(sizeof(int*) * get_area(map));
	while ((temp = get_row(map[i])))
	{
		ret[i] = (int*)malloc(sizeof(int) * ft_arrsize(temp));
		set_line(ret[i], temp);
		i++;
	}
	return (ret);
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
