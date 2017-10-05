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