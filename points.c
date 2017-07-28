/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:48:44 by rvinnako          #+#    #+#             */
/*   Updated: 2017/07/28 12:54:19 by rvinnako         ###   ########.fr       */
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


t_list	*point_list(t_map *map)
{
	int		x;
	int		y;
	t_list	*begin_list;
	t_list	*temp;
	t_point	point;

	y = 0;
	x = 0;
	point = new_point(x, y, map->map[y][x]);
	begin_list = ft_lstnew(point, POINT_SIZE);
	y++;
	while (y < map->map_y)
	{
		x = 1;
		while (x < map->map_x)
		{
			point = new_point(x, y, map->map[y][x]);
			temp = ft_lstnew(point);
			begin_list = ft_lstadd(begin_list, temp);
			free(temp);
			x++;
		}
		y++;
	}
	return (begin_list);
}

int		main(int ac, char **av)
{
	int		fd;
	char	**arr;
	t_map	map;
	t_list	*p_list;

	if (ac < 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	p_list = point_list(&map);
	while (p_list)
	{
		printf("%f\n", p_list->content->x);
		p_list = p_list->next;
	}
	return (0);
}
