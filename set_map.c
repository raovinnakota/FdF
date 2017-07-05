/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/03 16:00:11 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/05 16:24:34 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	**get_row(char *str)
{
	char **row;

	row = ft_strsplit(str, 32);
	return (row);
}

void 	set_line(int **int_arr, char **row)
{
	int		c_count;
	int		i_count;

	c_count = 0;
	i_count = 0;
	while (row[c_count])
	{
		*int_arr[i_count] = ft_atoi(row[c_count]);
		i_count++;
		c_count++;
	}
}

int		get_area(char **map)
{
	int i;
	int height;
	int width;

	height = 0;
	while (map[0][i])
	{
		if (ft_isdigit(map[0][i]))
			width++;
		i++;
	}
	while (map[height])
		height++;
	return (width * height);
}


int		**get_int_map(char **map)
{
	int		i;
	int		**ret;
	char	**temp;

	i = 0;
	ret = (int**)malloc(sizeof(int*) * get_area(map));
	while (temp = (get_row(map[i])))
	{
		set_line(&ret[i], temp);
		i++;
	}
	return (ret);
}


int		main(int ac, char **av)
{
	int		i;
	int 	j;
	int		fd;
	char	**map;
	char	**line;
	int		**arr;

	if (ac != 2)
		return (0);
	i = 0;
	fd = open(av[1], O_RDONLY);
	map = fill_map(fd);
	arr = get_int_map(map);
	while (map[i][0])
	{
		j = 0;
		while (map[i][j])
		{
			printf("%d", map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}
