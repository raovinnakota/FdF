/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:48:44 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/15 15:25:30 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	set_cart(t_point *point, int x, int y)
{
	point->cart_x = (float)(x);
	point->cart_y = (float)(y);
}

t_point	new_point(int x, int y, int z)
{
	t_point	ret;

	ret.x = (float)x;
	ret.y = (float)y;
	ret.z = (float)z;
	return (ret);
}

t_point	find_right(t_point *point_list, t_point *point, t_map *map)
{
	int		z;
	int 	goal_x;
	int 	goal_y;
	t_point	ret;

	z = 0;
	goal_x = ((int)point->cart_x + 1);
	goal_y = ((int)point->cart_y);
	while (z < map->map_area)
	{
		if ((point_list[z].cart_x == goal_x) && (point_list[z].cart_y == goal_y))
		{
			ret = point_list[z];
		}
		z++;
	}
	return (ret);
}

t_point	find_down(t_point *point_list, t_point *point, t_map *map)
{
	int		z;
	int 	goal_x;
	int 	goal_y;
	t_point	ret;

	z = 0;
	goal_x = ((int)point->cart_x);
	goal_y = ((int)point->cart_y + 1);
	while (z < map->map_area)
	{
		if ((point_list[z].cart_x == goal_x) && (point_list[z].cart_y == goal_y))
		{
			ret = point_list[z];
		}
		z++;
	}
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
	p_list = (t_point*)malloc(map->map_area * sizeof(float) * 7);
	while (y < map->map_y)
	{
		x = 1;
		while (x < map->map_x)
		{
			point = new_point((map->mid_x - x), (map->mid_y - y), (map->map[y][x]));
			set_cart(&point, x, y);
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
