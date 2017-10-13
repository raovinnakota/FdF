/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rvinnako <rvinnako@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/21 13:57:40 by rvinnako          #+#    #+#             */
/*   Updated: 2017/09/26 16:34:25 by rvinnako         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_funct(int keycode, void *param)
{
	if (keycode == 53)
		exit(0);
	if ((int)param == 0)
		return (0);
	return (0);
}

void	set_points(t_env *env, t_point *p_list)
{
	//t_point	right;
	//t_point	down;
	int		z;

	z = 0;
	rotate_graph(p_list, 0.3854 , env->map, 'z');
	rotate_graph(p_list, 0.0524, env->map, 'y');
	rotate_graph(p_list, 0.6982, env->map, 'x');
	while (z < env->map->map_area)
	{
		p_list[z].win_x = (p_list[z].x * env->scale) + (env->win_x / 2);
		p_list[z].win_y = (p_list[z].y * env->scale) + (env->win_y / 2);
		z++;
	}
}


int		main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_env 	*env;
	t_line	line;
	t_point *p_list;
	char	**arr;

	if (ac < 2)
	{
		printf("Include the test map\n");
		return (0);
	}
	line = init_line();
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	map = get_map(arr);
	env = init_env(&map);
	set_scale(env);
	p_list = point_list(env->map);
	draw_all(env, &line, p_list);
}
