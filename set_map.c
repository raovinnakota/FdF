/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/20 12:22:15 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/08 16:18:21 by rvinnako         ###   ########.fr       */
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
	map->mid_x = width / 2;
	map->mid_y = height / 2;
	map->map_area = (map->map_x * map->map_y);
}


void	get_int_map(t_map *map, char **arr)
{
	int		i;
	char	**temp;

	i = 0;
	map->map = (int**)malloc(sizeof(int*) * map->map_area);
	while ((temp = get_row(arr[i])))
	{
		map->map[i] = (int*)malloc(sizeof(int) * map->map_x);
		set_line(map->map[i], temp);
		i++;
	}
}

t_map	get_map(char **arr)
{
	t_map ret;

	set_dimensions(&ret, arr);
	get_int_map(&ret, arr);
	return (ret);
}

/*
int		main(int ac, char **av)
{
	int a;
	int b;
	int fd;
	t_map map;
	char **arr;

	if (ac != 2)
		return (0);
	a = 0;
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map  = get_map(arr);
	while (a < map.map_y)
	{
		printf("\n");
		b = 0;
		while (b < map.map_x)
		{
			printf("%d ", map.map[a][b]);
			b++;
		}
		a++;
	}
	return (0);
}
*/
