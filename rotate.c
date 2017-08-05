/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 12:40:35 by rvinnako          #+#    #+#             */
/*   Updated: 2017/08/04 19:48:44 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


void	rotate_x(t_point *point, float angle)
{
	point->y = (point->y * cos(angle)) - (point->z * sin(angle));
}

void	rotate_y(t_point *point, float angle)
{
	point->x = (point->x * cos(angle)) + (point->z * sin(angle));
}

void	rotate_z(t_point *point, float angle)
{
	point->x = (point->x * cos(angle)) - (point->y * sin(angle));
	point->y = (point->x * sin(angle)) + (point->y * cos(angle));
}

void	rotate_graph(t_point *p_list, float angle, t_map *map, char axis)
{
	int		z;

	z = 0;
	while((z + 1) < map->map_area)
	{
		if (axis == 'x')
			rotate_x(&p_list[z], angle);
		if (axis == 'y')
			rotate_y(&p_list[z], angle);
		if (axis == 'z')
			rotate_z(&p_list[z], angle);
		z++;
	}
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
	rotate_graph(p_list, 2.094, &map);
	while ((z + 1) < map.map_area)
	{
		printf("x:%f y:%f z:%f\n", p_list[z].x, p_list[z].y, p_list[z].z);
		//rotate_x(&p_list[z], 2.094);
		//printf("x:%f y:%f z:%f\n", p_list[z].x, p_list[z].y, p_list[z].z);
		z++;
	}
	return (0);
}
*/
