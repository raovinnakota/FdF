/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/26 18:48:44 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 17:16:29 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


t_point	new_point(int x, int y, int z)
{
	t_point	ret;

	ret.x = (float)x;
	ret.y = (float)y;
	ret.z = (float)z / 4;
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
	p_list = (t_point*)malloc(map->map_area * sizeof(float) * 8);
	while (y < map->map_y)
	{
		x = 1;
		while (x < map->map_x)
		{
			point = new_point((x - map->mid_x), (y - map->mid_y), (map->map[y][x]));
			point.cart_x = (float)x;
			point.cart_y = (float)y;
			point.list_num = (float)z;
			p_list[z] = point;
			x++;
			z++;		
		}
		z++;
		y++;
	}
	return (p_list);
}