/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:48:44 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/08 16:12:01 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_point	new_point(int x, int y, int z)
{
	t_point	ret;

	ret.x = (float)x;
	ret.y = (float)y;
	ret.z = (float)z;
	return (ret);
}


t_point	*point_list(t_map *map)
{
	int		x;
	int		y;
	int		z;
	t_point	point;
	t_point	*p_list;

	y = 0;
	z = 0;
	p_list = (t_point*)malloc(map->map_area * sizeof(float) * 3);
	while (y < map->map_y)
	{
		x = 1;
		while (x < map->map_x)
		{
			point = new_point((map->mid_x - x + 1), (map->mid_y - y + 1), (map->map[y][x]));
			p_list[z] = point;
			x++;
			z++;
		}
		z++;
		y++;
	}
	return (p_list);
}

/*
int		main(int ac, char **av)
{
	int		fd;
	int		z;
	char	**arr;
	t_map	map;
	t_point	*p_list;

	if (ac < 2)
		return (0);
	z = 0;
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	p_list = point_list(&map);
	while ((z + 1) < map.map_area)
	{
		printf("x:%f y:%f z:%f\n", p_list[z].x, p_list[z].y, p_list[z].z);
		z++;
	}
	return (0);
}
*/
