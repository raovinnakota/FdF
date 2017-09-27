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
/*
void	draw_map(t_env *env, t_map *map)
{
	t_point	*p_list;
	//t_point	right;
	//t_point	down;
	int		z;

	z = 0;
	p_list = point_list(map);
	rotate_graph(p_list, 3.142, map, 'x');
	rotate_graph(p_list, 0.050, map, 'y');
	rotate_graph(p_list, 0.050, map, 'z');
	while (z + 1 < map->map_area)
	{
		//printf("x:%fy:%f\n", p_list[z].cart_x, p_list[z].cart_y);
		p_list[z].win_x = (p_list[z].x * env->scale) + (env->win_x / 2);
		p_list[z].win_y = (p_list[z].y * env->scale) + (env->win_y / 2);
		mlx_pixel_put(env->mlx_ptr, env->win_ptr, p_list[z].win_x, p_list[z].win_y, 0xFF00FF);
		z++;
	}
	z = 1;
	/*
	while (z + 1 < map->map_area)
	{
		printf("%d:%d:%d\n", z, z+1, z+(map->map_x));
		draw_line(&p_list[z], &p_list[z + 1], mlx_ptr, win_ptr);
		draw_line(&p_list[z], &p_list[z + (map->map_x)], mlx_ptr, win_ptr);
		z++;
	}*/
	//draw_line(&p_list[0], &p_list[10], mlx_ptr, win_ptr);
	//right = find_right(p_list, &p_list[0], map);
	//down = find_down(p_list, &p_list[0], map);
	//mlx_pixel_put(mlx_ptr, win_ptr, down.win_x, down.win_y, 0xFFFFFF);
	//mlx_pixel_put(mlx_ptr, win_ptr, right.win_x, right.win_y, 0xFFFFFF);
	//printf("down = x:%f, y:%f\n, win_x:%f, win_y:%f\n", down.cart_x, down.cart_y, down.win_x, down.win_y);
	//draw_line(&p_list[8], &right, mlx_ptr, win_ptr);
	//draw_line(&p_list[8], &down, mlx_ptr, win_ptr);
}


int		main(int ac, char **av)
{
	int		fd;
	t_map	map;
	t_env 	*env;
	char	**arr;

	if (ac < 2)
	{
		printf("Include the test map\n");
		return (0);
	}
	env = init_env()
	fd = open(av[1], O_RDONLY);
	arr = fill_map(fd);
	env->map = get_map(arr);
	env->mlx_ptr = mlx_init();
	env->win_ptr = mlx_new_window(env->mlx_ptr, env->win_x, env->win_y, av[1]);
	draw_map(env, &map);
	mlx_loop(env->mlx_ptr);
}
